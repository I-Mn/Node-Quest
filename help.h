#ifndef HELP_H
#define HELP_H

#include <iostream>
using namespace std;

void help() {
    cout << "=== Bantuan Permainan Node Quest ===\n";
    cout << "* Gunakan perintah arah (utara, selatan, barat, timur) untuk bergerak.\n";
    cout << "* Setiap node memiliki tipe: NORMAL, MONSTER, atau NPC.\n";
    cout << "* Lawan monster menggunakan pilihan aksi (Attack, Magic, Counter, Dodge).\n";
    cout << "* Kalahkan semua musuh di node untuk bisa melanjutkan.\n";
    cout << "* Input 'Cari toko' untuk mencari kembali toko yang sudah dilewati.\n";
    cout << "* Gunakan 'Upgrade' untuk meningkatkan statistik karakter.\n";
    cout << "* Gunakan 'Stats' untuk melihat statistik karakter.\n";
    cout << "* Kumpulkan EXP untuk naik stage dan membuka cerita.\n";
    cout << "* Jangan sampai HP habis, atau kamu akan kalah!\n";
    cout << "* Ketik 'help' kapan saja untuk melihat petunjuk ini.\n";
    cout << "=====================================\n";
}

#endif
