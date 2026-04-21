/*==============================================================*/
/* STUDI KASUS 2                                                */
/* Simulasi Sistem Printer dengan Fitur Cancel                  */
/*==============================================================*/

#ifndef QUEUE_DINAMIS_H
#define QUEUE_DINAMIS_H

#include "boolean.h"
#include <stdlib.h>
#define Nil NULL
#define AddressHead(Q) (Q)->HEAD 
#define AddressTail(Q) (Q)->TAIL 
#define MAX 100

/* Definisi tipe elemen */
typedef char infotype;

/* Definisi pointer */
typedef struct tElmt *address;

/* Definisi node */
typedef struct tElmt {
    infotype data[64]; 
    address next;  
} ElmtList;

/* Definisi Queue */
typedef struct {
    address HEAD;
    address TAIL;
} Queue;




void buatQueue(Queue *Q);

boolean queueIsEmpty(Queue Q);

infotype Front(Queue Q);

int tampilkanQueue(Queue Q);

void tambahQueue(Queue *Q, infotype X);

void hapusQueue(Queue *Q);

#endif