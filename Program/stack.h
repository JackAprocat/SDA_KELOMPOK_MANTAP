
#include "boolean.h"
#include <stdlib.h>
#define Nil NULL
#define AddressTop(S) (S)->TOP /* Penunjuk alamat TOP */

/* Definisi tipe elemen */
typedef int infotype;

/* Definisi pointer ke node */
typedef struct tElmt *address;

/* Definisi node */
typedef struct tElmt {
    infotype info; /* data */
    address next;  /* pointer ke elemen berikutnya */
} ElmtList;

/* Definisi Stack */
typedef struct {
    address TOP; /* pointer ke elemen teratas */
} Stack;

/*==============================================================*/
/*                      PROTOTYPE                               */
/*==============================================================*/

/* Konstruktor */
/* I.S. sembarang */
/* F.S. Stack kosong dengan TOP = NULL */
void CreateStack(Stack *S);

/* Validator */
/* Mengirim true jika stack kosong, sebaliknya false jika tidak kosong */
boolean IsEmpty(Stack S);

/* Getter */
/* Mengirim nilai info elemen teratas stack */
infotype Top(Stack S);

/* Operator menambahkan elemen ke dalam stack*/
/* I.S. Stack terdefinisi */
/* F.S. Elemen X ditambahkan sebagai TOP */
void Push(Stack *S, infotype X);

/* Operator menghapus elemen ke dalam stack, sekaligus mengambil nilai info elemen yang dihapus*/
/* I.S. Stack tidak kosong */
/* F.S. Elemen TOP dihapus dan disimpan di X */
void Pop(Stack *S, infotype *X);

