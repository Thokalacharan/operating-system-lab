#include <stdio.h>
#include <dirent.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    char buff[100]; 
    DIR *dirp;      
    struct dirent *dptr; 
    
    printf("\n\nENTER DIRECTORY NAME: ");
    scanf("%s", buff);

   
    if ((dirp = opendir(buff)) == NULL) {
        
        printf("The given directory does not exist\n");
        exit(1); 
    }

  
    while ((dptr = readdir(dirp))) {
        printf("%s\n", dptr->d_name);
    }

    
    closedir(dirp);

    return 0; 
}


#include <stdio.h>     // Include standard I/O functions like printf and scanf
#include <dirent.h>     // Include directory operations functions (opendir, readdir, closedir)
#include <stdlib.h>     // Include standard library functions like exit

int main(int argc, char *argv[]) {
    char buff[100];     // Declare a character array to store the directory name entered by the user
    DIR *dirp;          // Declare a pointer to a DIR structure (represents an open directory stream)
    struct dirent *dptr; // Declare a pointer to a dirent structure (used to store information about each directory entry)

    // Ask the user to enter the directory name
    printf("\n\nENTER DIRECTORY NAME: ");
    // Read the directory name from user input and store it in 'buff'
    scanf("%s", buff);

    // Try to open the directory specified by the user
    if ((dirp = opendir(buff)) == NULL) {
        // If opendir returns NULL, the directory couldn't be opened (it might not exist or there might be an error)
        printf("The given directory does not exist\n");
        // Exit the program with a non-zero status (indicating an error)
        exit(1);
    }

    // Read and print each directory entry one by one
    while ((dptr = readdir(dirp))) {
        // Print the name of the directory entry (file, subdirectory, etc.)
        printf("%s\n", dptr->d_name);
    }

    // Close the directory stream after reading all entries
    closedir(dirp);

    // Return 0 to indicate the program finished successfully
    return 0;
}
