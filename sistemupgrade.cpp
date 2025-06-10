#include <iostream>
#include <string>
#include <cmath>
#include "alur.h"
#include "data.h"
#include "inventory.h"

using namespace std;

// struct PlayerStats {
//     int hp = 100;
//     int attack = 25;
//     int magic = 25;
//     int counter = 25;
//     int evade = 25;
//     int skillPoint = 10;
//     int exp = 0;
//     int level = 1;
//     int stage = 1;
// };

// Upgrade Stat Tree
// struct UpgradeNode {
//     string statName;
//     int level;
//     int bonusValue;
//     bool unlocked;
//     UpgradeNode* next;
// };

// UpgradeNode* createNextNode(UpgradeNode* prev) {
//     int nextLevel = prev->level + 1;
//     int bonus = (int)(prev->bonusValue * 1.5);
//     UpgradeNode* newNode = new UpgradeNode{prev->statName, nextLevel, bonus, false, nullptr};
//     prev->next = newNode;
//     return newNode;
// }

// UpgradeNode* buildStatTree(string statName, int baseBonus) {
//     return new UpgradeNode{statName, 1, baseBonus, false, nullptr};
// }

// void upgradeFromTree(PlayerStats& player, UpgradeNode* node) {
//     if (player.skillPoint <= 0) {
//         cout << "Skill point tidak cukup.\n\n";
//         return;
//     }
//     while (node->unlocked) {
//         if (node->next == nullptr) {
//             node = createNextNode(node);
//         } else {
//             node = node->next;
//         }
//     }
//     node->unlocked = true;
//     player.skillPoint--;
//     if (node->statName == "hp") player.hp += node->bonusValue;
//     else if (node->statName == "attack") player.attack += node->bonusValue;
//     else if (node->statName == "magic") player.magic += node->bonusValue;
//     else if (node->statName == "counter") player.counter += node->bonusValue;
//     else if (node->statName == "evade") player.evade += node->bonusValue;

//     cout << "Upgrade " << node->statName << " Lv" << node->level << " berhasil! +" << node->bonusValue << endl << endl;
// }

// Poison Buff Logic
int poisonBuffTurns = 0;
const int poisonDamagePerTurn = 5;

void usePoisonBuff() {
    if (poisonBuffTurns > 0) {
        cout << "Buff poison sudah aktif, masih tersisa " << poisonBuffTurns << " giliran.\n";
    } else {
        poisonBuffTurns = 3;
        cout << "Buff poison aktif selama 3 giliran pada musuh!\n";
    }
    cout << endl;
}

void useInventoryItem(PlayerStats& player) {
    if (inventoryStack.empty()) {
        cout << "Inventory kosong.\n\n";
        return;
    }

    stack<string> tempStack = inventoryStack;
    tampilkanInventory(tempStack);

    // cout << "Pilih nomor item yang ingin digunakan: ";
    // int pilih;
    // cin >> pilih;
    // cout << endl;

    // if (pilih < 1 || pilih > (int)tempStack.size()) {
    //     cout << "Pilihan tidak valid.\n\n";
    //     return;
    // }

    // // Cari item yang dipilih
    // stack<string> newStack;
    string selectedItem;
    // int target = (int)tempStack.size() - pilih;

    // for (int i = 0; i < target; ++i) {
    //     newStack.push(inventoryStack.top());
    //     inventoryStack.pop();
    // }

    selectedItem = inventoryStack.top();
    inventoryStack.pop(); // hapus item dari stack asli

    // while (!newStack.empty()) {
    //     inventoryStack.push(newStack.top());
    //     newStack.pop();
    // }

    cout << "Menggunakan item: " << selectedItem << endl;

    if (selectedItem == "Healing Poison") {
        player.hp += 15;
        cout << "HP +15.\n";
        usePoisonBuff();
    } 
    else if (selectedItem == "Magic Poison") {
        player.magic += 10;
        cout << "Magic +10.\n";
        usePoisonBuff();
    } 
    else if (selectedItem == "Buff Poison") {
        usePoisonBuff();
    } 
    else {
        cout << "Item tidak dikenali.\n";
    }

    cout << endl;
}

void tampilkanStats(const PlayerStats& p) {
    cout << "\n=== Player Stats ===" << endl;
    cout << "HP: " << p.hp << "\nAttack: " << p.attack << "\nMagic: " << p.magic
         << "\nCounter: " << p.counter << "\nEvade: " << p.evade
         << "\nSkill Point: " << p.skillPoint << endl;
    cout << "Poison Buff aktif giliran: " << poisonBuffTurns << endl;
    cout << "Exp: " << p.exp << "\nLevel: " << p.level << endl;
    cout << "Stage:" << p.stage << endl;
}

// Void Naikin Level dan Stage

void checkExpAndLevelUp(PlayerStats& player) {
    int expThreshold = 100;
    while (player.exp >= expThreshold) {
        player.exp -= expThreshold;
        player.level++;
        player.exp -= expThreshold;
        expThreshold += expThreshold * 1.5;
        player.skillPoint += 1;
        cout << "Level naik! Sekarang level " << player.level << endl;
    }
}

void checkLevelAndUpdateStage(PlayerStats& player, int& stage) {
    int newStage = player.level / 10;  // misal level 23 -> stage 2 (karena 23/10=2)
    if (newStage > stage) {
        stage = newStage;
        switch(stage) {
            case 1:
                stage1();
                break;
            case 2:
                stage2();
                break;
            case 3:
                stage3();
                break;
            case 4:
                ending();
                break;
            default:
                cout << "Stage tidak dikenal.\n";
                break;
        }
    }
}


void upgrade(string stat){
    int cost = 0;
    if (stat == "hp") {
        cost = (int)(5 * pow(1.5, upgrade_stats.upgrade_hp));
        if (player.gold < cost) {
            cout << "Gold tidak cukup untuk upgrade HP. Dibutuhkan: " << cost << ", Gold kamu: " << player.gold << endl;
            return;
        }
        player.gold -= cost;
        player_stats.hp += (int)(upgrade_stats.baseUpgrade_hp * pow(1.5, upgrade_stats.upgrade_hp));
        cout << "HP ditingkatkan +" << (int)(upgrade_stats.baseUpgrade_hp * pow(1.5, upgrade_stats.upgrade_hp)) << "! Total HP sekarang: " << player_stats.hp << endl;
        cout << "Gold terpakai: " << cost << ", Gold tersisa: " << player.gold << endl;
        upgrade_stats.upgrade_hp++;
        player_stats.skillPoint--;
    }
    else if (stat == "attack") {
        cost = (int)(5 * pow(1.5, upgrade_stats.upgrade_attack));
        if (player.gold < cost) {
            cout << "Gold tidak cukup untuk upgrade Attack. Dibutuhkan: " << cost << ", Gold kamu: " << player.gold << endl;
            return;
        }
        player.gold -= cost;
        player_stats.attack += (int)(upgrade_stats.baseUpgrade_attack * pow(1.5, upgrade_stats.upgrade_attack));
        cout << "Attack ditingkatkan +" << (int)(upgrade_stats.baseUpgrade_attack * pow(1.5, upgrade_stats.upgrade_attack)) << "! Total Attack sekarang: " << player_stats.attack << endl;
        cout << "Gold terpakai: " << cost << ", Gold tersisa: " << player.gold << endl;
        upgrade_stats.upgrade_attack++;
        player_stats.skillPoint--;
    }
    else if (stat == "magic") {
        cost = (int)(5 * pow(1.5, upgrade_stats.upgrade_magic));
        if (player.gold < cost) {
            cout << "Gold tidak cukup untuk upgrade Magic. Dibutuhkan: " << cost << ", Gold kamu: " << player.gold << endl;
            return;
        }
        player.gold -= cost;
        player_stats.magic += (int)(upgrade_stats.baseUpgrade_magic * pow(1.5, upgrade_stats.upgrade_magic));
        cout << "Magic ditingkatkan +" << (int)(upgrade_stats.baseUpgrade_magic * pow(1.5, upgrade_stats.upgrade_magic)) << "! Total Magic sekarang: " << player_stats.magic << endl;
        cout << "Gold terpakai: " << cost << ", Gold tersisa: " << player.gold << endl;
        upgrade_stats.upgrade_magic++;
        player_stats.skillPoint--;
    }
    else if (stat == "counter") {
        cost = (int)(5 * pow(1.5, upgrade_stats.upgrade_counter));
        if (player.gold < cost) {
            cout << "Gold tidak cukup untuk upgrade Counter. Dibutuhkan: " << cost << ", Gold kamu: " << player.gold << endl;
            return;
        }
        player.gold -= cost;
        player_stats.counter += (int)(upgrade_stats.baseUpgrade_counter * pow(1.5, upgrade_stats.upgrade_counter));
        cout << "Counter ditingkatkan +" << (int)(upgrade_stats.baseUpgrade_counter * pow(1.5, upgrade_stats.upgrade_counter)) << "! Total Counter sekarang: " << player_stats.counter << endl;
        cout << "Gold terpakai: " << cost << ", Gold tersisa: " << player.gold << endl;
        upgrade_stats.upgrade_counter++;
        player_stats.skillPoint--;
    }
    else if (stat == "evade") {
        cost = (int)(10 * pow(1.5, upgrade_stats.upgrade_evade));
        if (player_stats.evade >= 85){
            cout << "Evade sudah mencapai batas maksimum.\n";
            return;
        }
        if (player.gold < cost) {
            cout << "Gold tidak cukup untuk upgrade Evade. Dibutuhkan: " << cost << ", Gold kamu: " << player.gold << endl;
            return;
        }
        player.gold -= cost;
        player_stats.evade += (int)(upgrade_stats.baseUpgrade_evade * pow(1.2, upgrade_stats.upgrade_evade));
        cout << "Evade ditingkatkan +" << (int)(upgrade_stats.baseUpgrade_evade * pow(1.2, upgrade_stats.upgrade_evade)) << "! Total Evade sekarang: " << player_stats.evade << endl;
        cout << "Gold terpakai: " << cost << ", Gold tersisa: " << player.gold << endl;
        upgrade_stats.upgrade_evade++;
        player_stats.skillPoint--;
    }
    else {
        cout << "Stat tidak dikenali.\n";
    }
    cout << "Skill point tersisa: " << player_stats.skillPoint << endl;
}

void mainUpgrade() {
    PlayerStats player;

    // // Inisialisasi stat tree
    // UpgradeNode* hpTree = buildStatTree("hp", 10);
    // UpgradeNode* attackTree = buildStatTree("attack", 5);
    // UpgradeNode* magicTree = buildStatTree("magic", 5);
    // UpgradeNode* counterTree = buildStatTree("counter", 5);
    // UpgradeNode* evadeTree = buildStatTree("evade", 5);

    // Isi inventory awal
    // tambahItemKeInventory("Magic Poison");
    // tambahItemKeInventory("Healing Poison");
    // tambahItemKeInventory("Buff Poison");

    string pilihan;

    while (true) {
        tampilkanStats(player);
        cout << "Skill Point: " << player_stats.skillPoint << endl;
        
        // cout << "\n------------------------\n";
        // cout << "Pilih aksi:\n";
        // cout << "1. Upgrade stat (hp/attack/magic/counter/evade)\n";
        // cout << "2. Pakai item inventory\n";
        // cout << "3. Keluar\n";
        // cout << "Pilihan: ";
        // cin >> pilihan;
        // cout << endl;

        // if (pilihan == "1") {
            cout << "Pilih stat untuk upgrade (hp/attack/magic/counter/evade)/keluar: ";
            cin >> pilihan;
            cout << endl;
            if (pilihan == "keluar") {
                cout << "Keluar dari menu upgrade.\n";
                break;
            }
            if (player_stats.skillPoint <= 0) {
                cout << "Skill point tidak cukup untuk upgrade.\n\n";
                continue;
            }else{
                upgrade(pilihan);
            }

        // } 
        // else if (pilihan == "2") {
        //     useInventoryItem(player);
        // } 
        // else if (pilihan == "3") {
        //     cout << "Keluar dari program.\n";
        //     break;
        // } 
        // else {
        //     cout << "Pilihan tidak dikenali.\n\n";
        // }

        // // Efek poison buff ke musuh setiap giliran
        // if (poisonBuffTurns > 0) {
        //     cout << "Musuh terkena poison damage " << poisonDamagePerTurn << " HP.\n";
        //     poisonBuffTurns--;
        //     if (poisonBuffTurns == 0) cout << "Buff poison pada musuh habis.\n";
        //     cout << endl;
        // }
    }

}

bool jualItemDariInventory(const string& item) {
    stack<string> tempStack;
    bool found = false;
    // Pindahkan semua item ke tempStack, kecuali yang ingin dijual (pertama ditemukan)
    while (!inventoryStack.empty()) {
        if (!found && inventoryStack.top() == item) {
            inventoryStack.pop();
            found = true;
            break;
        } else {
            tempStack.push(inventoryStack.top());
            inventoryStack.pop();
        }
    }
    // Kembalikan item lain ke inventoryStack
    while (!tempStack.empty()) {
        inventoryStack.push(tempStack.top());
        tempStack.pop();
    }
    return found;
}
