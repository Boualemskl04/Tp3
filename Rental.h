#ifndef RENTAL_H
#define RENTAL_H

#include "struct.h"

TOF* open_file(char *, char);
void write_entete(TOF *);
void read_entete(TOF *);
void close(TOF *);

RentalR create_rentalR(Customer, Game, int, Date, Date, float);
int search_rental(TOF *, int, RentalR *);
void displayAllrentals(TOF *);
int saverentaldisk(TOF *, RentalR);
void write_blockr(TOF *, blockr *, int);
int read_blockr(TOF *, blockr *, int);
RentalD create_rentalD(RentalR);

int buildSparseIndex(SparseIndex[], TOF *);
int buildDenseIndex(DenseIndex[], TOF *);
void saveSparseIndex(SparseIndex[], int, const char *);
void saveDenseIndex(DenseIndex[], int, const char *);
int searchUsingSparseIndex(SparseIndex[], int, int);
int searchUsingDenseIndex(DenseIndex[], const char *, int *, int *);

#endif
