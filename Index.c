#include "index.h"
#include <string.h>

// Construction de l'index sparse (basé sur rentalID)
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

// Construction de l'index dense (basé sur le nom du client)
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

// Sauvegarde de l'index sparse dans un fichier
void saveSparseIndex(SparseIndex index[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(index, sizeof(SparseIndex), count, file);
    fclose(file);
}

// Sauvegarde de l'index dense dans un fichier
void saveDenseIndex(DenseIndex index[], int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    fwrite(index, sizeof(DenseIndex), count, file);
    fclose(file);
}

// Chargement de l'index sparse depuis un fichier
int loadSparseIndex(SparseIndex index[], const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) return -1;

    int count = 0;
    while (fread(&index[count], sizeof(SparseIndex), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}

// Chargement de l'index dense depuis un fichier
int loadDenseIndex(DenseIndex index[], const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) return -1;

    int count = 0;
    while (fread(&index[count], sizeof(DenseIndex), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}

// Recherche avec l'index sparse
int searchUsingSparseIndex(SparseIndex index[], int size, int rentalID) {
    for (int i = 0; i < size; i++) {
        if (index[i].rentalID == rentalID) {
            return index[i].blockNum;
        }
    }
    return -1;
}

// Recherche avec l'index dense
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
