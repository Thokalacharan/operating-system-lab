#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_BLOCKS 100 // Total number of blocks in the disk

// Disk array to keep track of free and allocated blocks
bool disk[TOTAL_BLOCKS];

// Function to initialize all blocks as free
void initializeDisk() {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        disk[i] = false; // false means block is free
    }
}

// Function to find a free block
int findFreeBlock() {
    for (int i = 0; i < TOTAL_BLOCKS; i++) {
        if (!disk[i]) {
            return i;
        }
    }
    return -1; // No free block available
}

int main() {
    int numFiles, fileSize, indexBlock, freeBlock;
    char fileName[20];

    // Initialize the disk
    initializeDisk();

    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++) {
        printf("\nEnter the name of file %d: ", i + 1);
        scanf("%s", fileName);

        printf("Enter the size of the file (number of blocks): ");
        scanf("%d", &fileSize);

        // Allocate the index block
        indexBlock = findFreeBlock();
        if (indexBlock == -1) {
            printf("No free blocks available for the index block. Allocation failed!\n");
            return 1;
        }
        disk[indexBlock] = true; // Mark the index block as allocated

        // Allocate data blocks
        int dataBlocks[fileSize];
        int allocated = 0;

        for (int j = 0; j < fileSize; j++) {
            freeBlock = findFreeBlock();
            if (freeBlock == -1) {
                printf("Not enough free blocks for the file. Allocation failed!\n");
                return 1;
            }
            disk[freeBlock] = true; // Mark block as allocated
            dataBlocks[allocated++] = freeBlock;
        }

        // Print the file allocation details
        printf("\nFile Name: %s\n", fileName);
        printf("Index Block: %d\n", indexBlock);
        printf("Data Blocks: ");
        for (int j = 0; j < fileSize; j++) {
            printf("%d ", dataBlocks[j]);
        }
        printf("\n");
    }

    printf("\nFile Allocation Simulation Complete!\n");

    return 0;
}
