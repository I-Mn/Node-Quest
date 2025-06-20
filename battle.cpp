#include <iostream>
#include <queue>
#include <string>
#include "data.h"
#include "inventory.h"
#include <chrono>
#include <thread>
using namespace std;
#include "ascii.cpp"

enum Skill { ATTACK, MAGIC, COUNTER, DODGE , POISON};

string skillToString(Skill s) {
    switch (s) {
        case ATTACK: return "Attack";
        case MAGIC: return "Magic";
        case COUNTER: return "Counter";
        case DODGE: return "Dodge";
        case POISON: return "Poison";
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
        if (x <= vertex_map[posisi].monsters[0].evadeChance) {
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
    clearScreen();
    const auto& monster_list = vertex_map[posisi].monsters;
    cout << "Ada " << monster_list.size() << " monster di sini:\n";
            for (int j = 0; j < 2; ++j) {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "." << flush;
        }
    player.HP = player_stats.hp;
    int nomor = 1;
    while (!vertex_map[posisi].monsters.empty()) {
        MonsterInstance& enemy = vertex_map[posisi].monsters[0];
        string ascii = getEnemyAscii(enemy.name);
        cout << endl;
        // system("cls");
        clearScreen();
        const auto& monster_list = vertex_map[posisi].monsters;
        cout << "Ada " << monster_list.size() << " monster di sini:\n";
        cout << ascii;
        cout <<"\n"<< nomor <<" === Lawan " << enemy.name << " (HP: " << enemy.hp << ")"
        <<"(Level: "<< enemy.level<<")"<<"(Attack: "<<enemy.damageAttack<<" )"<< "(Magic: "<<enemy.damageMagic<<" )" << "(Counter: "<<enemy.damageCounter<<" ) ==="<<  endl;
        cout << "HP Kamu: " << player.HP << endl;
        
        bool usedPoison = false;
        int magicPoisonBuff = 1;
        int buffPoisonBuff = 1;
        int healPoisonBuff = 0;
        int choice;
        int damageToEnemy = 0;
        int damageToPlayer = 0;
        bool enemyStunned = false;
        bool stunNextTurn = false;
        bool playerStunned = false;
        bool stunPlayerNextTurn = false;
        while (true) {
            cout << "Pilihan Aksi:\n";
            cout << "1. Attack  - Serangan langsung, menang melawan Magic.\n";
            cout << "2. Magic   - Serangan sihir, menang melawan Counter.\n";
            cout << "3. Counter - Menangkis serangan fisik, menang melawan Attack.\n";
            cout << "4. Dodge   - Menghindari serangan, tergantung stat evade.\n";
            cout << "5. Potion  - Gunakan potion dari backpack.\n";
            cout << "Pilih aksi (1-5): ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 5.\n";
                continue;
            }
            if (choice == 22) {
                cout << "Menggunakan cheat mode!\n";
                damageToEnemy = 9999999; 
                enemy.hp = 0;
                break;
            }
            if (choice < 1 || choice > 5) {
                cout << "Pilihan tidak valid! Masukkan angka antara 1 dan 5.\n";
                continue;
            }
            if (choice == 5) {
                if (usedPoison) {
                    cout << "Kamu hanya bisa menggunakan 1 poison per giliran!\n";
                    continue;
                }
                if (inventoryStack.empty()) {
                    cout << "Inventory kosong.\n";
                    continue;
                }
                string topPoison = inventoryStack.top();
                inventoryStack.pop();
                cout << "Kamu menggunakan " << topPoison << "!\n";
                if (topPoison == "Healing Poison") {
                    int heal = (int)(0.3 * player_stats.hp);
                    player.HP = min(player.HP + heal, player_stats.hp);
                    cout << "HP bertambah " << heal << ". HP sekarang: " << player.HP << endl;
                    usedPoison = true;
                } else if (topPoison == "Magic Poison") {
                    magicPoisonBuff = 3;
                    cout << "Serangan magic x3 untuk giliran ini.\n";
                    usedPoison = true;
                } else if (topPoison == "Buff Poison") {
                    buffPoisonBuff = 3;
                    cout << "Serangan attack & counter x3 untuk giliran ini.\n";
                    usedPoison = true;
                } else if (topPoison == "Stun Potion") {
                    stunNextTurn = true;
                    cout << "Kamu menggunakan Stun Potion! Musuh akan terkena stun di ronde berikutnya.\n";
                    usedPoison = true;
                } else if (topPoison == "Player Stun Potion") {
                    stunPlayerNextTurn = true;
                    cout << "Kamu menggunakan Player Stun Potion! Kamu akan terkena stun di ronde berikutnya.\n";
                    usedPoison = true;
                } else {
                    cout << "Item tidak dikenal, tidak ada efek.\n";
                }
                continue;
            }
            break;
            if (choice == 22){
            damageToEnemy = 9999999;
        }

        }

        Skill playerSkill = static_cast<Skill>(choice - 1);
        Skill enemySkill = getRandomSkill(0);

        cout << "\nKamu: " << skillToString(playerSkill) << "  |  Musuh: " << skillToString(enemySkill) << endl;
        for (int j = 0; j < 3; ++j) {
            this_thread::sleep_for(chrono::milliseconds(500));
            cout << "." << flush;
        }
        cout << endl;

        
        if (playerSkill == DODGE && enemySkill == DODGE) {
            cout << "Kedua pihak menghindar! Tidak ada yang terkena serangan.\n";
            continue;
        }

        if (enemyStunned) {
            cout << "Musuh terkena stun dan tidak bisa menyerang ronde ini!\n";
            damageToPlayer = 0;
            enemyStunned = false; 
        } else {
            if (enemySkill == ATTACK) damageToPlayer = enemy.damageAttack;
            else if (enemySkill == MAGIC) damageToPlayer = enemy.damageMagic;
            else if (enemySkill == COUNTER) damageToPlayer = enemy.damageCounter;
        }
        if (playerStunned) {
            cout << "Kamu terkena stun dan tidak bisa menyerang ronde ini!\n";
            damageToEnemy = 0;
            playerStunned = false; 
        } else {
            if (playerSkill == ATTACK) damageToEnemy = player_stats.attack * buffPoisonBuff;
            else if (playerSkill == MAGIC) damageToEnemy = player_stats.magic * magicPoisonBuff;
            else if (playerSkill == COUNTER) damageToEnemy = player_stats.counter * buffPoisonBuff;
        }

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

            int stunChance = randomizer(1, 100);
            if (stunNextTurn || stunChance <= 40) {
                cout << "Musuh terkena stun dan tidak bisa menyerang ronde berikutnya!\n";
                enemyStunned = true;
                stunNextTurn = false;
            }
            // Cek stun chance jika musuh berhasil dodge
            int stunPlayerChance = randomizer(1, 100);
            if (stunPlayerNextTurn || stunPlayerChance <= 40) {
                cout << "Kamu terkena stun dan tidak bisa menyerang ronde berikutnya!\n";
                playerStunned = true;
                stunPlayerNextTurn = false;
            }
            continue;
        }

        cout << "HP Musuh sekarang: " << max(0, enemy.hp) << endl;
        cout << "HP Kamu sekarang : " << max(0, player.HP) << endl;

            if (player.HP <= 0) {
            cout << "Kamu kalah dalam pertempuran...\n";
            posisi = {0, 0}; 
            inventoryStack = stack<string>();
            int maxReduceGold = max(100, player.gold / 2);
            int reduceGold = min(maxReduceGold, player.gold);
            if (player_stats.level > 10){
             player_stats.level = max(10, (player_stats.level/10) * 10);
            }else{
            player_stats.level = 1;
}
            player_stats.exp = 0;
            player.gold -= reduceGold;
            cout << "Kamu kehilangan " << reduceGold << " gold. Gold tersisa: " << player.gold << endl;
            cout << "Semua item di inventory telah dibuang.\n";
            cout << "Level kamu dikurangi ke " << player_stats.level << ". EXP direset ke 0.\n";
            cout << "Kamu kembali ke titik awal.\n";
            break;
        }
        if (enemy.hp <= 0) {
            cout << "Musuh dikalahkan!\n";
            nomor++;
            int totalXP =+ enemy.expReward;
            vertex_map[posisi].monsters.erase(vertex_map[posisi].monsters.begin());
            if (vertex_map[posisi].monsters.empty()) {
                vertex_map[posisi].defeated = 1;
                cout << "Semua musuh di node ini telah dikalahkan!\n";
                player_stats.exp += totalXP;
                player.gold += (int)(totalXP / 2);
                cout << "Kamu mendapatkan " << totalXP << " EXP dan " << totalXP / 2 << " gold!\n";
                totalXP = 0;
                break;
            }
             cout << "\nTekan 'Enter' untuk melanjutkan pertarungan...\n";
            cin.clear();
            cin.get();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "\nTekan 'Enter' untuk melanjutkan pertarungan...\n";
        cin.clear();
        cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}