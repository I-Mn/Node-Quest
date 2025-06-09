#include <iostream>
#include <queue>
#include <string>
#include "data.h"
#include <chrono>
#include <thread>
using namespace std;

// vertex_map[posisi].monsters[i].name



// Gunakan enum Skill dari file ini
enum Skill { ATTACK, MAGIC, COUNTER, DODGE };

string skillToString(Skill s) {
    switch (s) {
        case ATTACK: return "Attack";
        case MAGIC: return "Magic";
        case COUNTER: return "Counter";
        case DODGE: return "Dodge";
        default: return "Unknown";
    }
}

Skill getRandomSkill(int i) {
    int roll = randomizer(1, 100);
    int acc = vertex_map[posisi].monsters[i].attack;
    if (roll <= acc) {
        return ATTACK;
    }
    acc += vertex_map[posisi].monsters[i].magic;
    if (roll <= acc) {
        return MAGIC;
    }
    acc += vertex_map[posisi].monsters[i].counter;
    if (roll <= acc) {
        return COUNTER;
    }
    return DODGE;
}

string dodgeAttempt(string side){
    if (side == "player"){
        int x = randomizer(1, 100);
        if (x <= player_stats.evade) {
            return "dodge";
        } else {
            return "fail";
        }
    }
    else if (side == "enemy"){
        int x = randomizer(1, 100);
        if (x <= vertex_map[posisi].monsters[0].evade) {
            return "dodge";
        } else {
            return "fail";
        }
    }
return "Unknown";}

string resolveBattle(Skill player, Skill enemy) {
    if (player == enemy)
        return "draw";
    if ((player == ATTACK && enemy == MAGIC) ||
        (player == MAGIC && enemy == COUNTER) ||
        (player == COUNTER && enemy == ATTACK))
        return "player";
    if ((player == ATTACK && enemy == COUNTER) ||
        (player == MAGIC && enemy == ATTACK) ||
        (player == COUNTER && enemy == MAGIC))
        return "enemy";

    if (player == DODGE && enemy == DODGE) {
        return "dodge";
    } else if (player == DODGE) {
        string result = dodgeAttempt("player");
        if (result == "dodge") {
            cout << "Kamu berhasil menghindar!\n";
            return "dodge";
        } else {
            cout << "Kamu gagal menghindar! Musuh menyerang!\n";
            return "enemy";
        }
    } else if (enemy == DODGE) {
        string result = dodgeAttempt("enemy");
        if (result == "dodge") {
            cout << "Musuh berhasil menghindar!\n";
            return "dodge";
        } else {
            cout << "Musuh gagal menghindar! Kamu menyerang!\n";
            return "player";
        }
    }
return "Unknown";}

void fightEnemy(Player& player) {
    while (!vertex_map[posisi].monsters.empty()) {
        MonsterInstance& enemy = vertex_map[posisi].monsters[0];

        system ("cls");
        cout << "\n=== Lawan " << enemy.name << " (HP: " << enemy.hp << ") ===\n" << endl;
        cout << "Pilihan Aksi:\n";
        cout << "1. Attack  - Serangan langsung, menang melawan Magic.\n";
        cout << "2. Magic   - Serangan sihir, menang melawan Counter.\n";
        cout << "3. Counter - Menangkis serangan fisik, menang melawan Attack.\n";
        cout << "4. Dodge   - Menghindari serangan, tergantung stat evade.\n";
        cout << "5. Potion  - Gunakan potion dari backpack.\n";

        int choice;
        while (true) {
            cout << "Pilih aksi (1-5): ";
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 5.\n";
            } else {
                break;
            }
        }

        // string buff = "";
        // if (choice == 5) {
        //     if (player.potion > 0) {
        //         if player.potion

        Skill playerSkill = static_cast<Skill>(choice - 1);
        Skill enemySkill = getRandomSkill(0); // selalu melawan monsters[0]

        cout << "\nKamu: " << skillToString(playerSkill) << "  |  Musuh: " << skillToString(enemySkill) << endl;
        for (int j = 0; j < 3; ++j) {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "." << flush;
        }
        cout << endl;

        // Jika keduanya dodge
        if (playerSkill == DODGE && enemySkill == DODGE) {
            cout << "Kedua pihak menghindar! Tidak ada yang terkena serangan.\n";
            continue;
        }

        int damageToEnemy = 0;
        int damageToPlayer = 0;

        if (playerSkill == ATTACK) damageToEnemy = player_stats.attack;
        else if (playerSkill == MAGIC) damageToEnemy = player_stats.magic;
        else if (playerSkill == COUNTER) damageToEnemy = player_stats.counter;

        if (enemySkill == ATTACK) damageToPlayer = enemy.damageAttack;
        else if (enemySkill == MAGIC) damageToPlayer = enemy.damageMagic;
        else if (enemySkill == COUNTER) damageToPlayer = enemy.damageCounter;

        string result = resolveBattle(playerSkill, enemySkill);

        if (result == "draw") {
            cout << "Pertarungan seri! Kedua pihak terkena sebagian damage.\n";
            enemy.hp -= damageToEnemy / 2;
            player.HP -= damageToPlayer / 2;
            cout << "Musuh menerima " << damageToEnemy / 2 << " damage.\n";
            cout << "Kamu menerima " << damageToPlayer / 2 << " damage.\n";
        } else if (result == "player") {
            enemy.hp -= damageToEnemy;
            cout << "Kamu menang! Musuh menerima " << damageToEnemy << " damage.\n";
        } else if (result == "enemy") {
            player.HP -= damageToPlayer;
            cout << "Musuh menang! Kamu menerima " << damageToPlayer << " damage.\n";
        } else if (result == "dodge") {
            continue; // tidak ada damage yang masuk
        }

        cout << "HP Musuh sekarang: " << max(0, enemy.hp) << endl;
        cout << "HP Kamu sekarang : " << max(0, player.HP) << endl;

        // Cek apakah musuh kalah
        if (enemy.hp <= 0) {
            cout << "Musuh dikalahkan!\n";
            vertex_map[posisi].monsters.erase(vertex_map[posisi].monsters.begin());
            if (vertex_map[posisi].monsters.empty()) {
                vertex_map[posisi].defeated = 1;
                cout << "Semua musuh di node ini telah dikalahkan!\n";
                break;
            }
            continue;
        }

        // Cek apakah player kalah
        if (player.HP <= 0) {
            cout << "Kamu kalah dalam pertempuran...\n";
            // Tambahkan logika Game Over
            break;
        }
    }
}
