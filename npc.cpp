#include <iostream>
using namespace std;
#include "data.h"

void npc_goblin(Player player)
{
    cout << "Goblin Pedagang\n";
    cout << "\nKamu melihat goblin yang tampak kesal karena gerobaknya rusak,\n";
    cout << "padahal gerobak itu penuh dengan botol dan ramuan yang akan dia jual.\n";
    cout << "Dia melihatmu dengan wajah penuh tipu muslihat dan meminta bantuanmu\n";
    cout << "\nAnak muda... Bisa bantu aku memasang roda pada gerobakku?\n";
    cout << "\na. Membantu\n";
    cout << "b. Abaikan dan lanjutkan perjalanan\n";
    cout << "c. Menolak dengan sopan karena takut\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Dia sangat berterima kasih dan memberikanmu HEALING POISON dan MAGIC POISON.\n";
        player.healing_poison += 1;
        player.magic_poison += 1;
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu tidak bisa mengakses shop.\n";
    }
    else
    {
        cout << "Ternyata goblin itu adalah ketua pedagang yang jujur.\n";
    }
}

void npc_wanita_aneh(Player player)
{
    cout << "Wanita Aneh\n";
    cout << "Saat dalam perjalanan seorang wanita yang mengenakan baju mejikuhibiniu menghampirimu\n";
    cout << "\nJawab teka-teki ini, dan kau akan mendapatkan MAGIC POISON\n";
    cout << "Jika salah… ya, terimalah konsekuensinya.\n";
    cout << "Aku tak hidup, tapi aku tumbuh. Tak punya paru-paru, tapi butuh udara. Apa aku?\n";
    cout << "\na. Api\n";
    cout << "b. Batu\n";
    cout << "c. Saya tidak ingin bermain teka-teki\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Kamu mendapatkan MAGIC POISON.\n";
        player.magic_poison += 1;
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu mendapatkan FAKE POISON.\n";
    }
    else
    {
        cout << "Kamu MATI\n";
    }
}