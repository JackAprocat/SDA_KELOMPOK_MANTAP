#include <stdlib.h>
#include <stdio.h>
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
        i++;
        P = P->next;
    }
    return i;
}

void tambahQueue(Queue *Q, infotype X){
    address P = (address) malloc(sizeof(ElmtList));
    P->data = X;
    P->next = Nil;

    if(IsEmpty(*Q)){
		AddressHead(Q) = P;
        AddressTail(Q) = P;
	} else {
        AddressTail(Q)->next = P;
        AddressTail(Q) = P;
    }
}

char hapusQueue(Queue *Q) {
    // Jika queue kosong
    if (IsEmpty(*Q)) {
        return '\0'; // representasi kosong
    }

    address temp = AddressHead(Q);
    char nilai = temp->data;

    // Geser head ke next
    AddressHead(Q) = temp->next;

    // Jika setelah dihapus jadi kosong
    if (AddressHead(Q) == Nil) {
        AddressTail(Q) = Nil;
    }

    // Bebaskan memori
    free(temp);

    return nilai;
}

//Pencetekan antrian
//Jika antrian kosong maka printf("Antrian kosong.\n")
//I.S: awalnya kosong
//I.S: mencetak antrian yang ada saat ini
void CetakAntrian(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Antrian kosong.\n");
    } else {
        printf("Kondisi antrian saat ini: [ ");
        address P = AddressHead(&Q);
        while (P != Nil) {
            printf("%d ", P->data);
            P = P->next;
        }
        printf("]\n");
    }
}