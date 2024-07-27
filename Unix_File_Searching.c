#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>                                 // directory entry
#include <sys/stat.h>                               // for struct stat
#include <ctype.h>                                  // for strcasecmp
#include <libgen.h>?                                 // for getline


int search_Folder_Recursive(char *path, char *folderName){

    DIR *dir;
    struct dirent *ent;                             // struct dirent defined in direct.h ; directory entry
    /* struct dirent{
            d_name;     Name of the File or Subdirectory
            d_ino;      Inode Number of the File or Subdirectory
            d_off;      Offset of the next directory entry
            d_reclen;   Length of the directory entry
            d_type;     Type of the File or Subdirectory
    }
    */

    /* Now, Set the dir as the root directory. We want to start searching from the very base */
    dir = opendir(path);

    if (dir == NULL){
        perror("opendir");
        return -1;
    }

    /* ITERATION BEGINS HERE - Through all the Directories and Subdirectories */
    while ((ent = readdir(dir)) != NULL){

        /*  Comparing Entries with these. Our focus should be on the first two.
            DT_REG : Regular File
            DT_DIR : Directory
            DT_LNK : Symbolic Link
            DT_BLK : Block Device
            DT_CHR : Character Device
            DT_FIFO : FIFO
            DT_SOCK : Socket
            DT_UNKNOWN : Unknown Type
        */

        /* If the current entry is a Directory */
        if (ent->d_type == DT_DIR){
            if(strcasecmp(ent->d_name, folderName) == 0){
                printf("Folder Found: %s\n", ent->d_name);
                closedir(dir);
                return 0;
            }

            if(strcasecmp(ent->d_name, ".") != 0 && strcasecmp(ent->d_name, "..") != 0){
                char new_path[1024];
                snprintf(new_path, sizeof(new_path), "%s/%s", path, ent->d_name);

                // Check if new_path is a directory before calling opendir
                struct stat st;
                if (stat(new_path, &st) == 0 && S_ISDIR(st.st_mode)) {
                    int ret = search_Folder_Recursive(new_path, folderName);
                    if (ret == 0) {
                        closedir(dir);
                        return ret;
                    }
                }
            }
        }
    }

    closedir(dir);
    return -1;
}

int main(int argc, char *argv[]){

    /* Take the input from the user for the Folder they want to search */
    /* Dynamic Memory should be used here, but we will work with static for now */
    char *folderName = NULL;
    size_t folderLen = 0;

    printf("Enter the Folder Name: ");
    ssize_t bytesRead = getline(&folderName, &folderLen, stdin);
    if( bytesRead == -1){
        perror("getline");
        return 1;
    }

    /* Remove the newline character from the input */
    folderName[strcspn(folderName, "\n")] = 0;

    /* Use the user defined function to search */
    int ret = search_Folder_Recursive("/", folderName);
    if (ret == 0){
        printf("Error Searching for Folder.\n");
    }

    free(folderName);
    return 0;
}
