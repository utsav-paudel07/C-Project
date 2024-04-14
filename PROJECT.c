#include <stdio.h>
#include <stdlib.h>

// Define a struct for file information
struct FileInfo {
    char filename[50];
    int filesize;
};

// Function prototypes
void addFile(struct FileInfo files[], int *fileCount); // Function to add a file
void displayFiles(struct FileInfo files[], int fileCount); // Function to display all files

int main() {
    struct FileInfo files[100]; // Array to store file information
    int fileCount = 0; // Variable to track the number of files
    
    int choice;
    
    do {
        // Display menu
        printf("\nFile Management System\n");
        printf("1. Add a file\n");
        printf("2. Display files\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addFile(files, &fileCount); // Argument passed by reference (Pointer)
                break;
            case 2:
                displayFiles(files, fileCount); // Arguments passed by value
                break;
            case 3:
                printf("Exiting...\n");
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1); // Infinite loop until user chooses to exit
    
    return 0;
}

// Function to add a file
void addFile(struct FileInfo files[], int *fileCount) {
    if (*fileCount >= 100) {
        printf("File limit reached. Cannot add more files.\n");
        return;
    }
    
    struct FileInfo newFile;
    printf("Enter filename: ");
    scanf("%s", newFile.filename); // Formatted input
    printf("Enter filesize (in bytes): ");
    scanf("%d", &newFile.filesize); // Formatted input
    
    files[*fileCount] = newFile; // Adding file to the array
    (*fileCount)++; // Incrementing file count
    
    printf("File added successfully.\n");
}

// Function to display all files
void displayFiles(struct FileInfo files[], int fileCount) {
    if (fileCount == 0) {
        printf("No files to display.\n");
        return;
    }
    
    printf("Files:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %d: %s (%d bytes)\n", i+1, files[i].filename, files[i].filesize); // Formatted output
    }
}

