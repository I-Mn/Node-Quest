#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct PlayerStats {
    int hp = 100;
    int attack = 25;
    int magic = 25;
    int counter = 25;
    int evade = 25;
    int skillPoint = 10;
};

struct UpgradeNode {
    string statName;     // "hp", "attack", etc
    int level;           // 1, 2, 3...
    int bonusValue;      // Tambahan stat kalau upgrade
    bool unlocked;
    UpgradeNode* next;   // anak: upgrade selanjutnya
};

UpgradeNode* buildStatTree(string statName, int baseBonus) {
    UpgradeNode* lv1 = new UpgradeNode{statName, 1, baseBonus, false, nullptr};
    UpgradeNode* lv2 = new UpgradeNode{statName, 2, (int)(baseBonus * 1.5), false, nullptr};
    UpgradeNode* lv3 = new UpgradeNode{statName, 3, (int)(baseBonus * 1.5 * 1.5), false, nullptr};

    lv1->next = lv2;
    lv2->next = lv3;

    return lv1;
}

void upgradeFromTree(PlayerStats& player, UpgradeNode* node) {
    if (player.skillPoint <= 0) {
        cout << "Skill point tidak cukup.\n";
        return;
    }

    while (node != nullptr && node->unlocked) {
        node = node->next;
    }

    if (node == nullptr) {
        cout << "Upgrade maksimum tercapai untuk stat ini.\n";
        return;
    }

    node->unlocked = true;
    player.skillPoint--;

    if (node->statName == "hp") player.hp += node->bonusValue;
    else if (node->statName == "attack") player.attack += node->bonusValue;
    else if (node->statName == "magic") player.magic += node->bonusValue;
    else if (node->statName == "counter") player.counter += node->bonusValue;
    else if (node->statName == "evade") player.evade += node->bonusValue;

    cout << "Upgrade " << node->statName << " Lv" << node->level << " berhasil! +" << node->bonusValue << endl;
}

void tampilkanStats(const PlayerStats& p) {
    cout << "\n=== Player Stats ===" << endl;
    cout << "HP: " << p.hp << "\nAttack: " << p.attack << "\nMagic: " << p.magic
         << "\nCounter: " << p.counter << "\nEvade: " << p.evade
         << "\nSkill Point: " << p.skillPoint << endl;
}

int main() {
    PlayerStats player;

    // Build upgrade trees
    UpgradeNode* hpTree = buildStatTree("hp", 10);
    UpgradeNode* attackTree = buildStatTree("attack", 5);
    UpgradeNode* magicTree = buildStatTree("magic", 5);
    UpgradeNode* counterTree = buildStatTree("counter", 5);
    UpgradeNode* evadeTree = buildStatTree("evade", 5);

    string pilihan;
    while (player.skillPoint > 0) {
        tampilkanStats(player);
        cout << "\nPilih stat untuk upgrade (hp/attack/magic/counter/evade/exit): ";
        cin >> pilihan;

        if (pilihan == "hp") upgradeFromTree(player, hpTree);
        else if (pilihan == "attack") upgradeFromTree(player, attackTree);
        else if (pilihan == "magic") upgradeFromTree(player, magicTree);
        else if (pilihan == "counter") upgradeFromTree(player, counterTree);
        else if (pilihan == "evade") upgradeFromTree(player, evadeTree);
        else if (pilihan == "exit") break;
        else cout << "Pilihan tidak dikenali.\n";
    }

    cout << "\nUpgrade selesai!" << endl;
    tampilkanStats(player);

    return 0;
}
