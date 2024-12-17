#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_TITLE_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 100

typedef struct Customer {
    int customerid;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char contactInfo[MAX_CONTACT_LENGTH];
} Customer;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Game {
    int gameid;
    char title[MAX_TITLE_LENGTH];
    float rentalPrice;
} Game;

typedef struct RentalR {
    int rentalid;
    Customer customer;
    Game game;
    Date rentalDate;
    Date returnDate;
    float totalprice;
} RentalR;

typedef struct RentalD {
    int rentalID;
    int cid;
    int gid;
    Date rentalDate;
    Date returnDate;
    float totalprice;
} RentalD;

typedef struct blockc {
    Customer tab[SIZE];
    int count;
} blockc;

typedef struct blockr {
    RentalD tab[SIZE];
    int count;
} blockr;

typedef struct blockg {
    Game tab[SIZE];
    int count;
} blockg;

typedef struct Header {
    int nb;
} Header;

typedef struct TOF {
    struct Header header;
    char* file;
} TOF;

// Sparse and Dense Index Structures
typedef struct SparseIndex {
    int rentalID;   // Key for sparse index
    int blockNum;   // Corresponding block
} SparseIndex;

typedef struct DenseIndex {
    char customerName[MAX_NAME_LENGTH]; // Key for dense index
    int blockNum;
    int position;
} DenseIndex;

#endif
