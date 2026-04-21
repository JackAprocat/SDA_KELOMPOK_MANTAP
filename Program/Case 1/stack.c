#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== IMPLEMENTASI ===== */

// PROSEDUR buatStack(s)
void buatStack(Stack* s) {
    s->top = NULL;
}

// PROSEDUR tambahStack(s, nilai)
void tambahStack(Stack* s, const char* nilai) {
    // Alokasi Node baru
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Alokasi memori gagal.\n");
        return;
    }
    
    // Salin nilai ke data
    strncpy(newNode->data, nilai, MAX_DATA - 1);
    newNode->data[MAX_DATA - 1] = '\0';
    
    // Sisipkan di depan top
    newNode->next = s->top;
    s->top = newNode;
}

// FUNGSI hapusStack(s) -> string
char* hapusStack(Stack* s) {
    static char empty[MAX_DATA] = "";
    
    if (s->top == NULL) {
        return empty;
    }
    
    // Simpan data teratas
    static char buffer[MAX_DATA];
    strncpy(buffer, s->top->data, MAX_DATA - 1);
    buffer[MAX_DATA - 1] = '\0';
    
    // Hapus node teratas
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    
    return buffer;
}

// FUNGSI stackIsEmpty(s) -> boolean
bool stackIsEmpty(Stack* s) {
    return (s->top == NULL);
}

// PROSEDUR tampilkanStack(s)
void tampilkanStack(Stack* s) {
    if (stackIsEmpty(s)) {
        printf(" kosong ");
        return;
    }
    
    Node* curr = s->top;
    while (curr != NULL) {
        printf("%s", curr->data);
        if (curr->next != NULL) {
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf("\n");
}
