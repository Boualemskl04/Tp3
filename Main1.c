#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "rental.h"
#include "index.h"

#define SPARSE_FILE "sparse_index.dat"
#define DENSE_FILE "dense_index.dat"

int main() {
    TOF *tof;
    char path[100];
    char mode;
    SparseIndex sparseIndex[SIZE * SIZE];
    DenseIndex denseIndex[SIZE * SIZE];
    int sparseCount, denseCount;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Open mode (A: Existing, N: New): ");
    scanf(" %c", &mode);

    tof = open_file(path, mode);
    if (tof == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    printf("\nBuilding indexes...\n");
    sparseCount = buildSparseIndex(sparseIndex, tof);
    denseCount = buildDenseIndex(denseIndex, tof);

    saveSparseIndex(sparseIndex, sparseCount, SPARSE_FILE);
    saveDenseIndex(denseIndex, denseCount, DENSE_FILE);
    printf("Indexes saved to files: %s and %s.\n", SPARSE_FILE, DENSE_FILE);

    printf("\nTesting search with indexes:\n");

    int rentalID, block, position;
    printf("Enter rental ID to search (using sparse index): ");
    scanf("%d", &rentalID);

    block = searchUsingSparseIndex(sparseIndex, sparseCount, rentalID);
    if (block != -1) {
        printf("Rental found in block: %d\n", block);
    } else {
        printf("Rental not found.\n");
    }

    char customerName[MAX_NAME_LENGTH];
    printf("\nEnter customer name to search (using dense index): ");
    scanf("%s", customerName);

    if (searchUsingDenseIndex(denseIndex, customerName, &block, &position) == 1) {
        printf("Customer found in block %d at position %d\n", block, position);
    } else {
        printf("Customer not found.\n");
    }

    close(tof);
    return 0;
}
