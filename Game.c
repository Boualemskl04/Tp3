#include "game.h"

// Construire un index sparse basé sur l'ID du jeu
int buildSparseGameIndex(SparseIndex index[], TOF *tof) {
    blockg bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockg(tof, &bloc, i) == -1) return -1;

        for (int j = 0; j < bloc.count; j++) {
            index[count].rentalID = bloc.tab[j].gameid;
            index[count].blockNum = i;
            count++;
        }
    }
    return count;
}

// Construire un index dense basé sur le titre du jeu
int buildDenseGameIndex(DenseIndex index[], TOF *tof) {
    blockg bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockg(tof, &bloc, i) == -1) return -1;

        for (int j = 0; j < bloc.count; j++) {
            strcpy(index[count].customerName, bloc.tab[j].title);
            index[count].blockNum = i;
            index[count].position = j;
            count++;
        }
    }
    return count;
}

// Sauvegarder les index dans des fichiers
void saveGameIndexes(SparseIndex sparse[], DenseIndex dense[], int sparseCount, int denseCount) {
    saveSparseIndex(sparse, sparseCount, "game_sparse_index.dat");
    saveDenseIndex(dense, denseCount, "game_dense_index.dat");
}
