#ifndef HELP_H
#define HELP_H

#include <iostream>
using namespace std;

void help() {
    cout << "=== Bantuan Permainan Node Quest ===\n";
    cout << "* Gunakan perintah arah (utara, selatan, timur, barat) untuk berpindah node.\n";
    cout << "* Setiap node memiliki tipe: STORY, MONSTER, NPC, atau EMPTY.\n";
    cout << "* Lawan monster satu per satu di node bertipe MONSTER hingga semua dikalahkan.\n";
    cout << "* Interaksi dengan NPC bisa memberi bantuan, cerita, atau kejutan.\n";
    cout << "* NPC Pedagang Keliling memungkinkan kamu membeli item saat ditemui.\n";
    cout << "* Jika ingin mencari lokasi toko terdekat, ketik 'toko'.\n";
    cout << "* Ketik 'upgrade' untuk membuka menu peningkatan statistik karakter.\n";
    cout << "* Ketik 'stats' untuk melihat statistik dan status karakter.\n";
    cout << "* Ketik 'inventory' untuk melihat daftar item yang kamu bawa.\n";
    cout << "* EXP didapat dari pertempuran dan interaksi. Naik level membuka stage cerita baru.\n";
    cout << "* Ketik 'help' kapan saja untuk melihat panduan ini lagi.\n";
    cout << "* Ketik 'keluar' untuk mengakhiri permainan.\n";
    cout << "=====================================\n";
}


#endif
