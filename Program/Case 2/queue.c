#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "queue.h"

void buatQueue(Queue *Q){
    AddressHead(Q) = Nil;
    AddressTail(Q) = Nil;
}

boolean queueIsEmpty(Queue Q){
    return (AddressHead(&Q) == Nil && AddressTail(&Q) == Nil);
}

infotype Front(Queue Q){
    return AddressHead(&Q)->data;
}

int tampilkanQueue(Queue Q){
    address P = AddressHead(&Q);
    int i = 0;

    while(P != Nil){
        printf("%s", P->data);
        if (P->next != Nil) printf(", ");
        i++;
        P = P->next;
    }
    return i;
}

void tambahQueue(Queue *Q, const char* X){
    address P = (address) malloc(sizeof(ElmtList));
    strncpy(P->data, X, 63);
    P->data[63] = '\0';
    P->next = Nil;

    if(queueIsEmpty(*Q)){
		AddressHead(Q) = P;
        AddressTail(Q) = P;
	} else {
        AddressTail(Q)->next = P;
        AddressTail(Q) = P;
    }
}

char* hapusQueue(Queue *Q) {
    if (queueIsEmpty(*Q)) {
        return NULL;
    }

    address temp = AddressHead(Q);
    static char buffer[64];
    strncpy(buffer, temp->data, 63);
    buffer[63] = '\0';

    AddressHead(Q) = temp->next;

    if (AddressHead(Q) == Nil) {
        AddressTail(Q) = Nil;
    }

    free(temp);

    return buffer;
}

void CetakAntrian(Queue Q) {
    if (queueIsEmpty(Q)) {
        printf("Antrian kosong.\n");
    } else {
        printf("Kondisi antrian saat ini: [ ");
        address P = AddressHead(&Q);
        while (P != Nil) {
            printf("%s ", P->data);
            P = P->next;
        }
        printf("]\n");
    }
}