#include <iostream>
#include "data.h"

using namespace std;

const PlayerStats roleStats[] = {
    {250, 350, 150, 250, 10}, // Warrior
    {150, 200, 400, 200, 10}, // Mage
    {200, 220, 150, 230, 40}, // Rogue
    {400, 205, 100, 200, 5}    // Tank
};

Role PickRole(){
    int choice;
    cout << "Pilih Role:\n";
    cout << "1. Warrior: Serangan fisik tinggi, HP besar.\n";
    cout << "2. Mage: Serangan sihir tinggi, HP rendah.\n";
    cout << "3. Rogue: Serangan cepat, menghindar tinggi.\n";
    cout << "4. Tank: HP sangat besar, serangan rendah.\n";
    cout << "Masukkan pilihan (1-4): ";
    cin >> choice;
    switch (choice) {
        case 1: return Role::WARRIOR;
        case 2: return Role::MAGE;
        case 3: return Role::ROGUE;
        case 4: return Role::TANK;
        default:
            cout << "Pilihan tidak valid";
            return PickRole(); // Minta input ulang jika tidak valid
    }
}

void createPlayer(Player& player, PlayerStats& player_stats) {
    Role role = PickRole();
    switch (role) {
        case Role::WARRIOR:
            player_stats = roleStats[0];
            cout << "Kamu memilih Warrior!\n";
            break;
        case Role::MAGE:
            player_stats = roleStats[1];
            cout << "Kamu memilih Mage!\n";
            break;
        case Role::ROGUE:
            player_stats = roleStats[2];
            cout << "Kamu memilih Rogue!\n";
            break;
        case Role::TANK:
            player_stats = roleStats[3];
            cout << "Kamu memilih Tank!\n";
            break;
    }
    player_stats.hp = roleStats[static_cast<int>(role)].hp;
    player_stats.attack = roleStats[static_cast<int>(role)].attack;
    player_stats.magic = roleStats[static_cast<int>(role)].magic;
    player_stats.counter = roleStats[static_cast<int>(role)].counter;
    player_stats.evade = roleStats[static_cast<int>(role)].evade;
    player_stats.role = role;
    cout << "Role kamu: " << static_cast<int>(role) << endl;
    cout << "Statistik awal:\n";
    tampilkanStats(player_stats);
}
