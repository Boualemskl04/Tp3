#ifndef GAME_H
#define GAME_H

#include "struct.h"

// Fonctions existantes
void insert_game(TOF *, Game);
int search_game(TOF *, int, Game *);
int read_blockg(TOF *, blockg *, int);
void write_blockg(TOF *, blockg *, int);
void displayAllgame(TOF *);

// Index pour game
int buildSparseGameIndex(SparseIndex[], TOF *);
int buildDenseGameIndex(DenseIndex[], TOF *);
void saveGameIndexes(SparseIndex[], DenseIndex[], int, int);

#endif
