#include <string.h>
#include "rental.h"

// Builds sparse index based on rental ID
int buildSparseIndex(SparseIndex index[], TOF *tof) {
    blockr bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockr(tof, &bloc, i) == -1) {
            return -1;
        }
        for (int j = 0; j < bloc.count; j++) {
            index[count].rentalID = bloc.tab[j].rentalID;
            index[count].blockNum = i;
            count++;
        }
    }
    return count;
}

// Builds dense index based on customer name
int buildDenseIndex(DenseIndex index[], TOF *tof) {
    blockr bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockr(tof, &bloc, i) == -1) {
            return -1;
        }
        for (int j = 0; j < bloc.count; j++) {
            strcpy(index[count].customerName, bloc.tab[j].rentalDate);
            index[count].blockNum = i;
            index[count].position = j;
            count++;
        }
    }
    return count;
}

// Save sparse index to file
void saveSparseIndex(SparseIndex index[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(index, sizeof(SparseIndex), count, file);
    fclose(file);
}

// Save dense index to file
void saveDenseIndex(DenseIndex index[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(index, sizeof(DenseIndex), count, file);
    fclose(file);
}

// Search using sparse index
int searchUsingSparseIndex(SparseIndex index[], int size, int rentalID) {
    for (int i = 0; i < size; i++) {
        if (index[i].rentalID == rentalID) {
            return index[i].blockNum;
        }
    }
    return -1;
}

// Search using dense index
int searchUsingDenseIndex(DenseIndex index[], const char *name, int *block, int *position) {
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(index[i].customerName, name) == 0) {
            *block = index[i].blockNum;
            *position = index[i].position;
            return 1;
        }
    }
    return -1;
}
