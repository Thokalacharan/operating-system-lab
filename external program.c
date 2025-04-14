#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int nob, blocks[30];
} ft[30];

void main() {
    int i, j, n;
    char s[20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    // Input file details
    for (i = 0; i < n; i++) {
        printf("\nEnter file name %d: ", i + 1);
        scanf("%s", ft[i].name);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &ft[i].nob);

        printf("Enter the blocks of the file: ");
        for (j = 0; j < ft[i].nob; j++) {
            scanf("%d", &ft[i].blocks[j]);
        }
    }

    // Searching for a file
    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("\nFile Not Found\n");
    } else {
        // Display file details
        printf("\nFILE NAME\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
        printf("%s\t\t%d\t\t", ft[i].name, ft[i].nob);
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d ", ft[i].blocks[j]);
        }
        printf("\n");
    }
}
