#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queue.h"

void tambahDokumen(Queue *Q)
{
    char nama[MAX];

    printf("Masukkan nama dokumen: ");
    scanf(" %[^\n]", nama);

    queue_enqueue(Q, nama);
    printf("Dokumen '%s' ditambahkan ke antrian.\n", nama);
}

void cetakDokumen(Queue *Q, Stack *S)
{
    if (queue_isEmpty(*Q))
    {
        printf("Antrian kosong, tidak ada dokumen untuk dicetak.\n");
        return;
    }
    char *nama = queue_dequeue(Q);
    stack_push(S, nama);

    printf("Mencetak dokumen: '%s'\n", nama);
}

void cancelCetak(Stack *S)
{
    if (stack_isEmpty(*S))
    {
        printf("Riwayat kosong, tidak ada yang bisa dicancel.\n");
        return;
    }

    char *nama = stack_pop(S);
    printf("Cancel: dokumen '%s' dihapus dari riwayat.\n", nama);
}

void tampilkanAntrian(Queue Q)
{
    printf("Antrian : [");
    queue_tampilkan(Q);
    printf("]\n");
}

void tampilkanRiwayat(Stack S)
{
    printf("Riwayat : [");
    stack_tampilkan(S);
    printf("]\n");
}

int main()
{
    Queue antrian;
    Stack riwayat;
    CreateQueue(&antrian);
    int pilihan = 0;

    while (pilihan != 6)
    {
        switch (pilihan)
        {
        case 1:
            tambahDokumen(&antrian);
            break;

        case 2:
            cetakDokumen(&antrian, &riwayat);
            break;

        case 3:
        cancelCetak(&riwayat);
            break;

        case 4:
            tampilkanAntrian(antrian);
            break;

        case 5:
            tampilkanRiwayat(riwayat);
            break;

        default:
            break;
        }
    }
}