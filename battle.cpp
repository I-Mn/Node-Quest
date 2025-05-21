#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enum untuk skill
enum Skill { ATTACK, MAGIC, COUNTER, DODGE };

// Struktur Musuh
struct Enemy {
    string name;
    int hp;
    int expReward;
};

// Struktur Pemain
struct Player {
    int hp = 0;          
    int level = 1;
    int exp = 0;

    void gainReward(int amount) {
        hp += amount;
        if (hp > 100) hp = 100; // Batas maksimal HP 100
        cout << "\nKamu menang! Mendapat +" << amount << " HP. Total HP sekarang: " << hp << endl;
    }
    

    bool isAlive() {
        return hp > 0;
    }
};

// Konversi skill ke string
string skillToString(Skill s) {
    switch (s) {
        case ATTACK: return "Attack";
        case MAGIC: return "Magic";
        case COUNTER: return "Counter";
        case DODGE: return "Dodge";
        default: return "Unknown";
    }
}

// Random skill musuh
Skill getRandomSkill() {
    return static_cast<Skill>(rand() % 4);
}

// Penentuan hasil pertarungan suit
string resolveBattle(Skill player, Skill enemy) {
    if (player == enemy)
        return "draw";
    if ((player == ATTACK && enemy == MAGIC) ||
        (player == MAGIC && enemy == COUNTER) ||
        (player == COUNTER && enemy == ATTACK))
        return "player";
    return "enemy";
}

// Pertarungan 
bool fightEnemy(Player& player, Enemy& enemy) {
    cout << "\n=== Lawan " << enemy.name << " (HP: " << enemy.hp << ") ===\n" << endl;

    // Deskripsi skill
    cout << "Pilihan Aksi:\n";
    cout << "1. Attack  - Serangan langsung, menang melawan Magic.\n";
    cout << "2. Magic   - Serangan sihir, menang melawan Counter.\n";
    cout << "3. Counter - Menangkis serangan fisik, menang melawan Attack.\n";
    cout << "4. Dodge   - Menghindari serangan, tidak menyerang balik.\n";

    int choice;
    while (true) {
        cout << "Pilih aksi [1-4]: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 4.\n";
        } else {
            break;
        }
    }

    Skill playerSkill = static_cast<Skill>(choice - 1);
    Skill enemySkill = getRandomSkill();

    cout << "\nKamu: " << skillToString(playerSkill) << "  |  Musuh: " << skillToString(enemySkill) << endl;

    string result = resolveBattle(playerSkill, enemySkill);

    if (playerSkill == DODGE) {
        cout << "\nKamu menghindar! Tidak ada damage.\n";
        return true;
    }

    if (result == "draw") {
        cout << "\nSerangan imbang! Tidak ada pemenang.\n";
        return false;
    } else if (result == "player") {
        cout << "\nKamu menang dalam satu ronde!\n";
        player.gainReward(enemy.expReward);
        return true;
    } else {
        cout << "\nKamu kalah dalam satu ronde!\n";
        return false;
    }
}

// Main pertarungan: sistem queue
void battle(Player& player, queue<Enemy>& enemyQueue) {
    while (!enemyQueue.empty()) {
        Enemy current = enemyQueue.front();
        enemyQueue.pop();

        bool menang = fightEnemy(player, current);
        if (!menang) {
            cout << "\nKamu gagal mengalahkan " << current.name << ". Game Over!\n";
            return;
        }
    }

    cout << "\nKamu berhasil mengalahkan semua musuh! Menang total!\n";
}

int main() {
    srand(time(0));
    Player player;

    queue<Enemy> musuh;
    musuh.push({"Tung Tung Sahur", 30, 20});
    musuh.push({"Tralaleo", 40, 20});
    musuh.push({"Bombardilo Crocodilo", 50, 25});
    musuh.push({"Brbr Patapim", 30, 20});
    musuh.push({"Boborito Bandito", 40, 25});
    musuh.push({"Bombombini Guzini", 60, 30});

    cout << "\n===================";
    cout << "\n    Suit Battle    ";
    cout << "\n===================\n";
    cout << "\nNote: HP awal kamu adalah 0. Jika menang akan tambah HP\n";

    battle(player, musuh);

    return 0;
}
