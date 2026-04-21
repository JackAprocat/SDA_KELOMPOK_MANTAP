#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_DATA 100

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
void buatStack(Stack* s);
void tambahStack(Stack* s, const char* nilai);
char* hapusStack(Stack* s);
bool stackIsEmpty(Stack* s);
void tampilkanStack(Stack* s);

#endif
