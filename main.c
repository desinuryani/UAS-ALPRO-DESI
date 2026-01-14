#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX 30

int nim[MAX];
float nilai[MAX][3]; // [][0]=Tugas, [][1]=UTS, [][2]=UAS
int jumlah = 0;

/* ===== FUNGSI REKURSIF ===== */
int faktorial(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* ===== FUNGSI DATA ===== */
void tampilData() {
    int i;
    if (jumlah == 0) {
        printf("\nData masih kosong\n");
        return;
    }

    printf("\nNIM\tTugas\tUTS\tUAS\n");
    for (i = 0; i < jumlah; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               nim[i], nilai[i][0], nilai[i][1], nilai[i][2]);
    }
}

void tambahData() {
    if (jumlah >= MAX) {
        printf("\nData sudah penuh!\n");
        return;
    }

    printf("\nMasukkan NIM: ");
    scanf("%d", &nim[jumlah]);
    printf("Nilai Tugas: ");
    scanf("%f", &nilai[jumlah][0]);
    printf("Nilai UTS: ");
    scanf("%f", &nilai[jumlah][1]);
    printf("Nilai UAS: ");
    scanf("%f", &nilai[jumlah][2]);

    jumlah++;
    printf("Data berhasil ditambahkan\n");
}

void ubahData() {
    int cari, i, found = 0;
    printf("\nMasukkan NIM yang ingin diubah: ");
    scanf("%d", &cari);

    for (i = 0; i < jumlah; i++) {
        if (nim[i] == cari) {
            printf("Nilai Tugas baru: ");
            scanf("%f", &nilai[i][0]);
            printf("Nilai UTS baru: ");
            scanf("%f", &nilai[i][1]);
            printf("Nilai UAS baru: ");
            scanf("%f", &nilai[i][2]);
            found = 1;
            printf("Data berhasil diubah\n");
            break;
        }
    }

    if (!found)
        printf("Data tidak ditemukan\n");
}

void hapusData() {
    int cari, i, j, found = 0;
    printf("\nMasukkan NIM yang ingin dihapus: ");
    scanf("%d", &cari);

    for (i = 0; i < jumlah; i++) {
        if (nim[i] == cari) {
            for (j = i; j < jumlah - 1; j++) {
                nim[j] = nim[j + 1];
                nilai[j][0] = nilai[j + 1][0];
                nilai[j][1] = nilai[j + 1][1];
                nilai[j][2] = nilai[j + 1][2];
            }
            jumlah--;
            found = 1;
            printf("Data berhasil dihapus\n");
            break;
        }
    }

    if (!found)
        printf("Data tidak ditemukan\n");
}

void olahNilai() {
    int i;
    float rata, max = -1, min = 101;
    int idxMax = 0, idxMin = 0;

    for (i = 0; i < jumlah; i++) {
        rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        printf("NIM %d rata-rata: %.2f\n", nim[i], rata);

        if (rata > max) {
            max = rata;
            idxMax = i;
        }
        if (rata < min) {
            min = rata;
            idxMin = i;
        }
    }

    printf("\nRata-rata tertinggi: %d (%.2f)\n", nim[idxMax], max);
    printf("Rata-rata terendah : %d (%.2f)\n", nim[idxMin], min);
}

void fiturRekursif() {
    int i;
    printf("\nFaktorial dari %d = %d\n", jumlah, faktorial(jumlah));

    printf("Fibonacci (%d data): ", jumlah);
    for (i = 0; i < jumlah; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

/* ===== PROGRAM UTAMA ===== */
int main() {
    int pilih;

    do {
        printf("\n=== MENU PROGRAM ===\n");
        printf("1. Tampilkan Data\n");
        printf("2. Tambah Data\n");
        printf("3. Ubah Data\n");
        printf("4. Hapus Data\n");
        printf("5. Olah Nilai\n");
        printf("6. Fitur Rekursif\n");
        printf("7. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: tampilData(); break;
            case 2: tambahData(); break;
            case 3: ubahData(); break;
            case 4: hapusData(); break;
            case 5: olahNilai(); break;
            case 6: fiturRekursif(); break;
            case 7: printf("Program selesai\n"); break;
            default: printf("Pilihan tidak valid\n");
        }
    } while (pilih != 7);

    return 0;
}

