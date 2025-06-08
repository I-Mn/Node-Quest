#include <iostream>
using namespace std;

// struct Player
// {
//     int HP = 100;
//     int healing_poison = 0;
//     int magic_poison = 0;
//     int buff_poison = 0;
//     int gold = 0;
//     int attack = 10;
//     int defense = 5;
//     int weapon_durability = 100;
//     int weapon_max_durability = 100;
//     int armor_durability = 100;
//     int armor_max_durability = 100;
// };

// NPC random

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
        cout << "Dia sangat berterima kasih dan memberikanmu diskon untuk HEALING POISON dan MAGIC POISON\n";
        int healing_poison_price = 25;
        int magic_poison_price = 30;
        int buff_poison_price = 50;

        cout << "\n1. HEALING POISON (" << healing_poison_price << " gold)\n";
        cout << "2. MAGIC POISON (" << magic_poison_price << " gold)\n";
        cout << "3. BUFF POISON (" << buff_poison_price << " gold)\n";
        cout << "4. Mungkin lain kali\n";
        cout << "Pilih: ";
        char Choice;
        cin >> Choice;

        if (Choice == '1')
        {
            if (player.gold >= healing_poison_price)
            {
                player.gold -= healing_poison_price;
                player.healing_poison++;
                cout << "Kamu membeli HEALING POISON.\n";
            }
            else
            {
                cout << "Gold kamu tidak cukup.\n";
            }
        }
        else if (Choice == '2')
        {
            if (player.gold >= magic_poison_price)
            {
                player.gold -= magic_poison_price;
                player.magic_poison++;
                cout << "Kamu membeli MAGIC POISON.\n";
            }
            else
            {
                cout << "Gold kamu tidak cukup.\n";
            }
        }
        else if (Choice == '3')
        {
            if (player.gold >= buff_poison_price)
            {
                player.gold -= buff_poison_price;
                player.buff_poison++;
                cout << "Kamu membeli BUFF POISON.\n";
            }
            else
            {
                cout << "Gold kamu tidak cukup.\n";
            }
        }
        else if (Choice == '4')
        {
            cout << "Baiklah, datang lagi lain kali!\n";
        }
        else
        {
            cout << "Pilihan tidak valid, pilih 1/2/3/4\n";
        }
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu tidak bisa mengakses shop\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Ternyata goblin itu adalah ketua pedagang yang jujur\n";
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

void npc_wanita_aneh(Player player)
{
    cout << "Wanita Aneh\n";
    cout << "Saat dalam perjalanan seorang wanita yang mengenakan baju mejikuhibiniu menghampirimu\n";
    cout << "\nJawab teka-teki ini, dan kau akan mendapatkan MAGIC POISON\n";
    cout << "Jika salah… ya, terimalah konsekuensinya\n";
    cout << "Aku tak hidup, tapi aku tumbuh. Tak punya paru-paru, tapi butuh udara. Apa aku?\n";
    cout << "\na. Api\n";
    cout << "b. Batu\n";
    cout << "c. Saya tidak ingin bermain teka-teki\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Kamu mendapatkan MAGIC POISON\n";
        player.magic_poison += 1;
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu mendapatkan FAKE POISON\n";
        player.HP -= 10;
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Ternyata wanita aneh itu adalah penyihir yang menyamar\n";
        cout << "Dia kesal dan menyerangmu HP-100\n";
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

void npc_anak_kecil(Player player)
{
    cout << "Anak kecil cerewet sedang membawa keranjang roti.\n";
    cout << "\"Halo, paman... Kau baru pulang dari medan perang, ya? Apakah kau juga pernah mengangkat senjata...?\"\n";
    cout << "\"Paman pernah membunuh seseorang...? Apakah karena itu... rekan-rekan paman tak kembali?\"\n";
    cout << "\"Apakah paman tidak menyesal telah membunuh seseorang....?\"\n";

    cout << "\na. \"Aku terpaksa… untuk bertahan.\" (+10 HP)\n";
    cout << "b. \"Tidak. Mereka pantas mendapatkannya.\" (-10 HP)\n";
    cout << "c. Mengabaikan anak kecil (Anak itu berlari sambil menangis)\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Perasaanmu sedih dan campur aduk. Hantu itu merasakn penyesalan dari kata-katamu\n";
        player.gold += 50;
        cout << "Gold kamu bertambah 50\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu membentak anak itu. Ternyata anak itu adalah hantu.\n";
        cout << "Dia berlari sambil menangis.\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Kamu mengabaikan anak itu.\n";
        cout << "Dia menatapmu dengan tajam dan itu membuatmu tidak nyamana\n";
        player.HP -= 10;
        cout << "HP kamu berkurang 10\n";
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

void npc_ayah(Player player)
{
    cout << "Kamu melihat seorang pria tua yang tampak lelah duduk di tepi jalan.\n";
    cout << "Dia mengenakan pakaian lusuh dan terlihat sangat sedih.\n";
    cout << "\"Anakku... aku kehilangan segalanya. Aku tidak punya apa-apa lagi.\"\n";
    cout << "\"Aku hanya ingin melihat senyummu, anakku.\"\n";

    cout << "\na. Memberikan 50 gold kepadanya (+50 HP)\n";
    cout << "b. Mengabaikannya\n";
    cout << "c. Memberikan 10 gold kepadanya (-10 HP)\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Kamu memberikan 50 gold kepadanya.\n";
        player.HP += 50;
        player.gold -= 50;
        cout << "HP kamu bertambah 50\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu mengabaikannya.\n";
        cout << "Dia menatapmu dengan harapan yang hancur.\n";
        player.HP -= 20;
        cout << "HP kamu berkurang 20\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Kamu memberikan 10 gold kepadanya.\n";
        player.HP += 10;
        player.gold -= 10;
        cout << "HP kamu berkurang 10\n";
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

void npc_pria_tua(Player player)
{
    cout << "Pria tua yang rapuh, memegang tongkat, duduk di dekat api unggun.\n";
    cout << "\"Kau terlihat lelah, anak muda... Mau duduk sebentar dan berbagi api denganku?\n";

    cout << "\na. Abaikan dan lanjutkan perjalanan.\n";
    cout << "b. Siapa kamu? Kalau kamu tidak menunjukan identitasmu akanku pukul.\n";
    cout << "c. Ikut duduk.\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Kamu mengabaikan pria tua itu dan melanjutkan perjalanan.\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Pria tua itu adalah bandit yang menyamar.\n";
        cout << "Dia takut dan memberikanmu HEALING POISON sebagai tanda perdamaian.\n";
        player.healing_poison += 1;
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Kamu duduk bersama pria tua itu.\n";
        cout << "Ternyata dia adalah bandit yang menyamar! Dia mencuri poison-mu saat kamu lengah.\n";
        if (player.healing_poison > 0)
            player.healing_poison -= 1;
        if (player.magic_poison > 0)
            player.magic_poison -= 1;
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

void npc_bandit_yang_menyamar(Player player)
{
    cout << "Seorang bandit yang menyamar, memegang pedang berkarat, wajahnya tertutup kain.\n";
    cout << "\"Aku tahu apa yang telah kulakukan. Tapi aku tak akan sembunyi dari masa laluku.\n";
    cout << "Sekarang aku memilih untuk melindungi, bukan menghancurkan.\"\n";

    cout << "\na. Jangan pura-pura tobat. Orang seperti kamu tak pantas hidup.\n";
    cout << "b. Dasar Sampah\n";
    cout << "c. Diam\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        player.HP -= 20;
        cout << "HP kamu berkurang 20.\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
        player.HP -= 15;
        cout << "HP kamu berkurang 15.\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Kamu memilih diam.\n";
        cout << "Bandit itu memanfaatkan kesempatan dan mencuri poison-mu!\n";
        if (player.healing_poison > 0)
            player.healing_poison -= 1;
        if (player.magic_poison > 0)
            player.magic_poison -= 1;
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c\n";
    }
}

int front = 0;
int back = 0;
void (*kapasitas[6])(Player);

void masuk(void (*npc)(Player)) {
    if (back < 6) {
        kapasitas[back++] = npc;
    }
}

void tampilkan_bergantian(Player player) {
    if (front < back) {
        kapasitas[front](player); 
        front = (front + 1) % back;
    }
}

int main() {
    Player player;

    masuk(npc_goblin);
    masuk(npc_wanita_aneh);
    masuk(npc_anak_kecil);
    masuk(npc_ayah);
    masuk(npc_pria_tua);
    masuk(npc_bandit_yang_menyamar);

    for (int i = 0; i < 6; i++) {
        tampilkan_bergantian(player);
    }

    return 0;
}

// NPC untuk membeli dan memnjual barang

void npc_dwarft(Player player)
{
    cout << "Seorang dwarf tampak sibuk menempa pedang di sebuah bengkel tua. Dia meilatmu.\n";
    cout << "Ah, seorang petualang! Kau mau kuperkuat senjatamu?\n";
    cout << "Aku bisa menambahkan kekuatan padanya. \n";

    cout << "\na. Ya, tolong tingkatkan pedangku.\n";
    cout << "b. Ya, tolong tingkatkan armorku.\n";
    cout << "c. Tidak, tolong perbaiki pedangku.\n";
    cout << "d. Tidak, tolong perbaiki armorku.\n";
    cout << "e. Aku ingin membeli senjata.\n";
    cout << "f. Mungkin lain kali.\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Tentu.\n";
        player.attack += 10;
        cout << "Seranganmu meningkat 10 poin!\n";
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Baiklah.\n";
        player.defense += 10;
        cout << "Pertahananmu meningkat 10 poin!\n";
    }
    else if (choice == 'c' || choice == 'C')
    {
        cout << "Dwarf itu memeriksa pedangmu dan mulai memperbaikinya.\n";
        player.weapon_durability = player.weapon_max_durability;
        cout << "Pedangmu diperbaiki dan kembali ke kondisi maksimal.\n";
    }
    else if (choice == 'd' || choice == 'D')
    {
        cout << "Dwarf itu memeriksa armormu dan mulai memperbaikinya.\n";
        player.armor_durability = player.armor_max_durability;
        cout << "Armormu diperbaiki dan kembali ke kondisi maksimal.\n";
    }
    else if (choice == 'e' || choice == 'E')
    {

        int sword_price = 100;
        int armor_price = 150;

        cout << "Harga Pedang: " << sword_price << " gold\n";
        cout << "Harga Armor: " << armor_price << " gold\n";

        cout << "Pilih yang ingin kau beli:\n";
        cout << "1. Pedang\n";
        cout << "2. Armor\n";
        cout << "3. Mungkin lain kali\n";

        cout << "Pilihanmu: ";
        int buy_choice;
        cin >> buy_choice;

        if (buy_choice == 1)
        {
            if (player.gold >= sword_price)
            {
                player.gold -= sword_price;
                cout << "Kamu membeli pedang baru seharga " << sword_price << " gold!\n";
            }
            else
            {
                cout << "Gold kamu tidak cukup untuk membeli pedang.\n";
            }
        }
        else if (buy_choice == 2)
        {
            if (player.gold >= armor_price)
            {
                player.gold -= armor_price;
                cout << "Kamu membeli armor baru seharga " << armor_price << " gold!\n";
            }
            else
            {
                cout << "Gold kamu tidak cukup untuk membeli armor.\n";
            }
        }
        else if (buy_choice == 3)
        {
            cout << "Baiklah, datanglah lagi lain kali!\n";
        }
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c/d/e.\n";
    }
}

void npc_pedagang_keliling(Player player)
{
    cout << "Seorang pedagang keliling berhenti di dekatmu sambil menawarkan barang dagangannya.\n";
    cout << "\"Halo, petualang! Aku punya beberapa ramuan yang dapat membantumu.\"\n";

    cout << "\na. Tunjukkan barang daganganmu.\n";
    cout << "b. Aku ingin menjual beberapa ramuan.\n";
    cout << "d. Mungkin lain kali.\n";

    char choice;
    cout << "Pilihanmu: ";
    cin >> choice;

    if (choice == 'a' || choice == 'A')
    {
        cout << "Ini ramuan yang aku punya:\n";
        cout << "1. Ramuan Healing (50 gold)\n";
        cout << "2. Ramuan Magic (60 gold)\n";
        cout << "3. Ramuan Buff (70 gold)\n";
        cout << "4. Mungkin lain kali.\n";
        cout << "Pilih ramuan yang ingin kamu beli: ";

        int buy_choice;
        cin >> buy_choice;

        int price = 0;

        if (buy_choice == 1)
        {
            price = 50;
        }
        else if (buy_choice == 2)
        {
            price = 60;
        }
        else if (buy_choice == 3)
        {
            price = 70;
        }
        else if (buy_choice == 4)
        {
            cout << "Baiklah, mungkin lain kali.\n";
            return;
        }
        else
        {
            cout << "Pilihan tidak valid, pilih 1/2/3/4.\n";
            return;
        }
    }
    else if (choice == 'b' || choice == 'B')
    {
        cout << "Kamu ingin menjual beberapa ramuan. Berapa banyak yang ingin kamu jual?\n";
        cout << "1. Ramuan Healing\n";
        cout << "2. Ramuan Magic\n";
        cout << "3. Ramuan Buff\n";
        cout << "4. Mungkin lain kali.\n";

        int sell_choice;
        cin >> sell_choice;

        if (sell_choice == 1)
        {
            if (player.healing_poison > 0)
            {
                player.healing_poison--;
                player.gold += 40;
                cout << "Kamu menjual Ramuan Healing.\n";
            }
            else
            {
                cout << "Kamu tidak memiliki Ramuan Healing untuk dijual.\n";
            }
        }
        else if (sell_choice == 2)
        {
            if (player.magic_poison > 0)
            {
                player.magic_poison--;
                player.gold += 50;
                cout << "Kamu menjual Ramuan Magic.\n";
            }
            else
            {
                cout << "Kamu tidak memiliki Ramuan Magic untuk dijual.\n";
            }
        }
        else if (sell_choice == 3)
        {
            if (player.buff_poison > 0)
            {
                player.buff_poison--;
                player.gold += 60;
                cout << "Kamu menjual Ramuan Buff.\n";
            }
            else
            {
                cout << "Kamu tidak memiliki Ramuan Buff untuk dijual.\n";
            }
        }
        else if (sell_choice == 4)
        {
            cout << "Baiklah, mungkin lain kali.\n";
        }
        else
        {
            cout << "Pilihan tidak valid, pilih 1/2/3/4.\n";
        }
    }
    else if (choice == 'd' || choice == 'D')
    {
        cout << "Baiklah, datang lagi lain kali!\n";
    }
    else
    {
        cout << "Pilihan tidak valid, pilih a/b/c/d.\n";
    }
}

int main() {
    Player player;

    while (true) {
        cout << "\nKamu ingin pergi ke toko apa?\n";
        cout << "a. Toko Senjata\n";
        cout << "b. Toko Ramuan\n";
        cout << "c. Keluar\n";

        char pilihan1;
        cout << "Pilihanmu: ";
        cin >> pilihan1;

        if (pilihan1 == 'a' || pilihan1 == 'A') {
            npc_dwarft(player);
        }
        else if (pilihan1 == 'b' || pilihan1 == 'B') {
            npc_pedagang_keliling(player);
        }
        else if (pilihan1 == 'c' || pilihan1 == 'C') {
            cout << "Keluar dari game.\n";
            break;
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}