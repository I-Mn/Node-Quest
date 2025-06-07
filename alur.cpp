#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

void waitForEnter() {
    cout << "\n[ Tekan ENTER untuk melanjutkan... ]";
    cin.ignore();
    cin.get();
}

void showIntro() {
    cout << "=====================================\n";
    cout << "     RPG CLI - 'Node Quest'\n";
    cout << "=====================================\n\n";
    cout << "Perang berakhir, tapi jiwanya hancur.\n";
    cout << "Seorang petani yang dipaksa untuk bertempur kini berjalan pulang,\n";
    cout << "melewati ladang yang telah berubah menjadi kuburan.\n";
    cout << "Dunia telah berubah, di depan sana, ada sesuatu yang telah menunggunya.\n";
    cout << "Mereka menyebutnya sebagai ANOMALI.\n";
    cout << "Hanya ada dua pilihan: bertarung atau mati.\n";

    waitForEnter();
}

void stage1() {
    cout << "\n--- STAGE 1 ---\n";
    cout << "Dia tiba di persimpangan jalan yang dikelilingi oleh kabut tebal.\n";
    cout << "Udara menjadi dingin, dan langkahnya terasa berat.\n";
    cout << "Tak ada suara burung, tak ada hembusan angin.\n";
    cout << "Lalu ANOMALI itu muncul, menghentikan langkanya.\n";
    cout << "Tidak ada jalan lain, sang prajurit pun bersiap untuk bertarung.\n";

    waitForEnter();
}

void stage2() {
    cout << "\n--- STAGE 2 ---\n";
    cout << "ANOMALI itu muncul lagi, kali ini jauh lebih mengancam dan kuat.\n";
    cout << "Namun, sang prajurit tetap bertarung.\n";
    cout << "Dia mengingat keluarganya, wajah-wajah yang selalu dia rindukan.\n";
    cout << "Meski ketakutan, dia melangkah dengan berani,\n";
    cout << "menolak rasa takut yang berusaha menguasainya.\n";
    cout << "Tak akan dia biarkan Anomali itu menang.\n";

    waitForEnter();
}

void stage3() {
    cout << "\n--- STAGE 3 ---\n";
    cout << "Dia kehabisan tenaga, tapi tujuannya sudah dekat.\n";
    cout << "Di depannya terbentang tanah terbuka yang sunyi dan kosong.\n";
    cout << "ANOMALI itu berdiri, menatap lurus ke arahnya.\n";
    cout << "ANOMALI itu mulai melangkah.\n";
    cout << "TIDAAAAK...\n";

    waitForEnter();
}

void ending() {
    cout << "\n=== AKHIR CERITA ===\n";
    cout << "Udara mulai terasa hangat, kabut perlahan menghilang.\n";
    cout << "Di kejauhan, dia sudah melihat kampung halamannya,\n";
    cout << "atap rumahnya mulai terlihat.\n";
    cout << "Dia mempercepat langkahnya, dadanya sesak oleh rasa rindu.\n";
    cout << "Langkahnya terhenti, wajah-wajah yang telah lama dia rindukan\n";
    cout << "menyambutnya dengan haru.\n";
    cout << "PETANI ITU AKHIRNYA PULANG.\n";

    waitForEnter();
}


