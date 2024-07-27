NOTE :- This whole repository is designed to aid me in learning the Low Level Implementations of C language.
--------------------------------------------------------------------------------------------------------------------------------------------------
Aim :- This Program is designed to perform simple File I/O in C Language. 
--------------------------------------------------------------------------------------------------------------------------------------------------
Algorithm --> 
1. Get the File name the user want to create/access. We are opening the File in W+ Mode.
2. If the File pointer returns a NULL value, the file doesn't get assigned an address within the Memory. So, it doesn't exist.
3. Take data from the User, and insert it into the File.
4. Rewind the pointer to the File's offset.
5. Close the File.
6. Read the content of the File (OPTIONAL).
--------------------------------------------------------------------------------------------------------------------------------------------------
New Concepts I learned about :- 

1. FILE: This is a structure defined in the C standard library (stdio.h) that represents a file stream.
         It contains information about the file, such as its name, mode (read, write, append, etc.), and current position.

2. scanf() with the %s format specifier expects a pointer to a mutable character array, where it can store the input string.
   So, don't use it to take input from the user and store it in 'const char *fileName' as it will render the content of filename Immutable.

3. We used fgets(), instead of scanf() as it is considered comparably safer to use.
   Some comparision -->

   fgets(char *buffer, int bufsize, FILE *stream)  -  Doesn't Require Format specifier, thus only reads strings and hence is invulnerable to malicious format specifiers.
                                                      Add a '\n' (newline) character at the end of the input string.
                                                      Prevents Buffer Overflow by limiting the number of characters read to the specified buffer size.
                                                      Returns NULL when facing EOF errors.

4. To remove the last newline character from the specified buffer:
   filename[strcspn(filename, "\n")] = 0;    OR     fileName[strlen(fileName) - 1] = '\0';

5. perror() is a function in the C standard library that prints an error message to the standard error stream (stderr) describing the last error that occurred in a system call or
   library function.

   perror(const char *s)

   'errno' is a global variable that is set by system calls and library functions to indicate the type of error that occurred.
   'perror()' uses the value of errno to determine the error message to print.

   Some key points to keep in mind when using perror():
        A. perror() only prints error messages to stderr, not to stdout.
        B. perror() uses the value of errno to determine the error message to print.
        C. perror() does not modify the value of errno.
        D. perror() is not thread-safe, as it uses a global variable (errno) to determine the error message.

    Here are some common values of errno:

    EACCES (13): Permission denied
    EBADF (9): Bad file descriptor
    EEXIST (17): File exists
    EFAULT (14): Bad address
    EINVAL (22): Invalid argument
    EIO (5): Input/output error
    EISDIR (21): Is a directory
    EMFILE (24): Too many open files
    ENAMETOOLONG (36): Name too long
    ENOENT (2): No such file or directory
    ENOMEM (12): Out of memory
    ENOTDIR (20): Not a directory
    EPERM (1): Operation not permitted
   
    These are just a few examples of the many possible values of errno. The specific values of errno can vary depending on the operating system and the library being used.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NOTE :- 'errno' is a global variable in the C standard library that is used to store the error code of the last error that occurred in a system call or library function.
         When a system call or library function encounters an error, it sets the value of 'errno' to a specific error code that indicates the type of error that occurred. 
         The error code is typically a small integer value that is defined in the <errno.h> header file.
        'errno' is used in conjunction with the 'perror()' function to print error messages to the standard error stream (stderr).
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
6. scanf()  :  Reads from the stdin.                Used for reading input from the user.
   fscanf() :  Reads from the FILE stream.          Used for reading input from the files.
   sscanf() :  Reads from a String.                 Used for Parsing strings.

7. printf()  : Prints out to stdout.
   fprintf() : Prints out to a file.
   sprintf() : Prints out to a string array.        SECURITY RISK -- Can cause buffer overflow. 'snprintf' can be used alternatively, as it establishes a fixed size for the specified buffer.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






   

