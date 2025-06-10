#include <iostream>
#include <string>
#include <cmath>
#include "alur.h"
#include "data.h"
#include "inventory.h"

using namespace std;

int expThreshold = 100;

void tampilkanStats(const PlayerStats& p) {
    cout << "\n=== Player Stats ===" << endl;
    cout << "HP: " << p.hp << "\nAttack: " << p.attack << "\nMagic: " << p.magic
         << "\nCounter: " << p.counter << "\nEvade: " << p.evade
         << "\nSkill Point: " << p.skillPoint << endl;
    cout << "Exp: " << p.exp << "\nLevel: " << p.level << endl;
    cout << "Gold: " << player.gold << endl;
    cout << "Sisa EXP untuk level up: " << expThreshold - p.exp << endl;
    cout << "Stage:" << p.stage << endl;
}

// Void Naikin Level dan Stage

void checkExpAndLevelUp(PlayerStats& player) {
    while (player.exp >= expThreshold) {
        player.exp -= expThreshold;
        player.level++;
        expThreshold += expThreshold * 1.1;
        player.skillPoint += 1;
        cout << "Level naik! Sekarang level " << player.level << endl;
    }
}

void checkLevelAndUpdateStage(PlayerStats& player) {
    int newStage = player.level / 10;
    if (newStage > player.stage) {
        player.stage = newStage;
        switch(player.stage) {
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

    string pilihan;

    while (true) {
        tampilkanStats(player);
        cout << "Skill Point: " << player_stats.skillPoint << endl;

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
    }

}

