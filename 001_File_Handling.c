#include <stdio.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 256
#define DEFAULT_DATA 25

int main(int argc, char *argv[]){

    FILE *filePointer;
    char fileName[MAX_FILENAME_LENGTH];
    int data = DEAULT_DATA;

    fgets(fileName, MAX_FILENAME_LENGTH, stdin);
    //filename[strcspn(filename, "\n")] = 0;
    fileName[strlen(fileName) - 1] = '\0';

    filePointer = fopen(fileName,"w+");

    if(filePointer == NULL){
        perror("Error");
        return 1;
    }

    fprintf(filePointer, "%d", data);
    rewind(filePointer);
    fscanf(filePointer, "%d", &data);

    fclose(filePointer);

    printf("This is the %s. And its content:- %d\n", fileName, data);

    return 0;
}










