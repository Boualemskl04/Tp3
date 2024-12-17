#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "struct.h"

// Fonctions existantes
void insert_customer(TOF *, Customer);
int search_customer(TOF *, int, Customer *);
int read_blockc(TOF *, blockc *, int);
void write_blockc(TOF *, blockc *, int);
void displayAllcustomer(TOF *);

// Index pour customer
int buildSparseCustomerIndex(SparseIndex[], TOF *);
int buildDenseCustomerIndex(DenseIndex[], TOF *);
void saveCustomerIndexes(SparseIndex[], DenseIndex[], int, int);

#endif
