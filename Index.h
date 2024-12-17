#ifndef INDEX_H
#define INDEX_H

#include "struct.h"

// Prototypes pour les index
int buildSparseIndex(SparseIndex[], TOF *);
int buildDenseIndex(DenseIndex[], TOF *);
void saveSparseIndex(SparseIndex[], int, const char *);
void saveDenseIndex(DenseIndex[], int, const char *);
int loadSparseIndex(SparseIndex[], const char *);
int loadDenseIndex(DenseIndex[], const char *);
int searchUsingSparseIndex(SparseIndex[], int, int);
int searchUsingDenseIndex(DenseIndex[], const char *, int *, int *);

#endif
