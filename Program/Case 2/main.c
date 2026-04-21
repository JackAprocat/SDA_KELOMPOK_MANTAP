#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queue.h"
#include "stack.h"

void tambahDokumen(Queue *Q)
{
    char nama[MAX];

    printf("Masukkan nama dokumen: ");
    scanf(" %[^\n]", nama);

    tambahQueue(Q, nama);
    printf("Dokumen '%s' ditambahkan ke antrian.\n", nama);
}

void cetakDokumen(Queue *Q, Stack *S)
{
    if (queueIsEmpty(*Q))
    {
        printf("Antrian kosong, tidak ada dokumen untuk dicetak.\n");
        return;
    }
    char *nama = hapusQueue(Q);
    tambahStack(S, nama);

    printf("Mencetak dokumen: '%s'\n", nama);
}

void cancelCetak(Stack *S)
{
    if (stackIsEmpty(S))
    {
        printf("Riwayat kosong, tidak ada yang bisa dicancel.\n");
        return;
    }

    char *nama = hapusStack(S);
    printf("Cancel: dokumen '%s' dihapus dari riwayat.\n", nama);
}

void tampilkanAntrian(Queue Q)
{
    printf("Antrian : [");
    tampilkanQueue(Q);
    printf("]\n");
}

void tampilkanRiwayat(Stack S)
{
    printf("Riwayat : [");
    tampilkanStack(&S);
    printf("]\n");
}

int main()
{
    Queue antrian;
    Stack riwayat;
    buatQueue(&antrian);
    buatStack(&riwayat);
    int pilihan = 0;

    while (pilihan != 6)
    {
        printf("\n=== Sistem Printer ===\n");
        printf("1. Tambah Dokumen\n");
        printf("2. Cetak Dokumen\n");
        printf("3. Cancel Cetak Dokumen Terakhir\n");
        printf("4. Tampilkan Antrian\n");
        printf("5. Tampilkan Riwayat\n");
        printf("6. Exit\n");
        printf("Pilih operasi: ");
        scanf("%d", &pilihan);

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
        case 6:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
        }
    }
    return 0;
}