#ifndef HELP_H
#define HELP_H

#include <iostream>
using namespace std;

void help() {
    cout << "=== Bantuan Permainan Node Quest ===\n";
    cout << "1. Gunakan perintah arah (kanan, kiri, maju, mundur) untuk bergerak.\n";
    cout << "2. Setiap node memiliki tipe: NORMAL, MONSTER, atau NPC.\n";
    cout << "3. Lawan monster menggunakan pilihan aksi (Attack, Magic, Counter, Dodge).\n";
    cout << "4. Kalahkan semua musuh di node untuk bisa melanjutkan.\n";
    cout << "5. Input 'Cari toko' untuk mencari kembali toko yang sudah dilewati.\n";
    cout << "6. Kumpulkan EXP untuk naik stage dan membuka cerita.\n";
    cout << "7. Jangan sampai HP habis, atau kamu akan kalah!\n";
    cout << "8. Ketik 'help' kapan saja untuk melihat petunjuk ini.\n";
    cout << "=====================================\n";
}

#endif
