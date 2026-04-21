#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_DATA 64

// Node untuk linked list
typedef struct Node {
    char data[MAX_DATA];
    struct Node* next;
} Node;

// Struktur Stack
typedef struct {
    Node* top;
} Stack;

/* ===== OPERASI STACK SESUAI PSEUDOCODE ===== */

// PROSEDUR buatStack(s)
void buatStack(Stack* s);

// PROSEDUR tambahStack(s, nilai)
void tambahStack(Stack* s, const char* nilai);

// FUNGSI hapusStack(s) -> string
char* hapusStack(Stack* s);

// FUNGSI stackIsEmpty(s) -> boolean
bool stackIsEmpty(Stack* s);

// PROSEDUR tampilkanStack(s)
void tampilkanStack(Stack* s);

#endif