#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "stack.h"

int main() {
    char s[256];
    printf("--- Validasi Tag HTML menggunakan Stack ---\n");
    printf("Masukkan string (ketik 'exit' untuk keluar):\n");
    
    while (1) {
        printf("> ");
        if (scanf(" %[^\n]", s) != 1) {
            break;
        }
        
        if (strcmp(s, "exit") == 0) {
            break;
        }

        Stack st;
        buatStack(&st);
        int i = 0;
        bool hasTags = false;
        bool isValid = true;
        
        while (s[i] != '\0') {
            if (s[i] == '<') {
                int isClosing = 0;
                i++;
                if (s[i] == '/') {
                    isClosing = 1;
                    i++;
                }
                
                char tagName[MAX_DATA];
                int j = 0;
                while (s[i] != '>' && s[i] != '\0') {
                    if (s[i] == '<') {
                        isValid = false;    // tag tidak valid karena ada '<' lain sebelum '>'
                        break;
                    }
                    if (j < MAX_DATA - 1) {
                        tagName[j++] = s[i];
                    }
                    i++;
                }
                
                if (!isValid) break;
                
                tagName[j] = '\0';
                
                if (s[i] != '>') {
                    isValid = false;    // bracket '>' tidak ditemukan
                    break;
                }
                
                if (strlen(tagName) == 0) {
                    isValid = false;    // tag kosong seperti <> atau </>
                    break;
                }
                
                hasTags = true;
                
                if (!isClosing) { // Jika tag pembuka
                    tambahStack(&st, tagName);
                } else {          // Jika tag penutup
                    if (stackIsEmpty(&st)) {
                        isValid = false;
                        break;
                    }
                    char* topTag = hapusStack(&st);
                    if (strcmp(topTag, tagName) != 0) {
                        isValid = false;
                        break;
                    }
                }
            }
            i++;
        }
        
        // Output akhir sesuai keinginan True / False
        if (isValid && hasTags && stackIsEmpty(&st)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    
    return 0;
}
