
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* --- Konstruktor --- */
/**
 * Prosedur: Membuat stack baru yang kosong
 * IS : S sembarang
 * FS : Terbentuk stack kosong dengan TOP = Nil (NULL)
 */
void CreateStack(Stack *S) {
    AddressTop(S) = Nil;
}

/* --- Validator --- */
/**
 * Fungsi: Mengecek apakah stack kosong
 * IS : S terdefinisi
 * FS : Mengirimkan true jika TOP == Nil, false jika tidak
 */
boolean IsEmpty(Stack S) {
    return (AddressTop(&S) == Nil);
}

/* --- Getter --- */
/**
 * Fungsi: Mengambil nilai elemen teratas stack
 * IS : S tidak kosong
 * FS : Mengirimkan nilai info elemen pada posisi TOP
 */
infotype Top(Stack S) {
    if (!IsEmpty(S)) {
        return (AddressTop(&S))->info;
    }
    return -999;
}

/* --- Operasi Stack --- */
/**
 * Prosedur: Menambahkan elemen ke dalam stack
 * IS : S terdefinisi, mungkin kosong. X nilai yang akan dimasukkan.
 * FS : Alokasi node baru berhasil, X menjadi elemen teratas (TOP baru).
 */
void Push(Stack *S, infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        P->info = X;
        P->next = AddressTop(S);
        AddressTop(S) = P;
    } else {
        printf("Alokasi Gagal\n");
    }
}

/**
 * Prosedur: Menghapus elemen dari stack
 * IS : S tidak kosong.
 * FS : Elemen teratas dihapus, nilainya disimpan di X, TOP menunjuk ke elemen berikutnya.
 */
void Pop(Stack *S, infotype *X) {
    if (!IsEmpty(*S)) {
        address P = AddressTop(S);
        *X = P->info;
        AddressTop(S) = P->next;
        free(P);
    } else {
        printf("Stack Kosong\n");
    }
}
