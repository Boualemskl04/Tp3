#include "customer.h"

// Construire un index sparse basé sur l'ID du client
int buildSparseCustomerIndex(SparseIndex index[], TOF *tof) {
    blockc bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockc(tof, &bloc, i) == -1) return -1;

        for (int j = 0; j < bloc.count; j++) {
            index[count].rentalID = bloc.tab[j].customerid;
            index[count].blockNum = i;
            count++;
        }
    }
    return count;
}

// Construire un index dense basé sur le nom du client
int buildDenseCustomerIndex(DenseIndex index[], TOF *tof) {
    blockc bloc;
    int count = 0;

    for (int i = 0; i < tof->header.nb; i++) {
        if (read_blockc(tof, &bloc, i) == -1) return -1;

        for (int j = 0; j < bloc.count; j++) {
            strcpy(index[count].customerName, bloc.tab[j].lastName);
            index[count].blockNum = i;
            index[count].position = j;
            count++;
        }
    }
    return count;
}

// Sauvegarder les index dans des fichiers
void saveCustomerIndexes(SparseIndex sparse[], DenseIndex dense[], int sparseCount, int denseCount) {
    saveSparseIndex(sparse, sparseCount, "customer_sparse_index.dat");
    saveDenseIndex(dense, denseCount, "customer_dense_index.dat");
}
