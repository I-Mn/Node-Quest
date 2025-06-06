#include <iostream>
#include <string>
#include <stack>
#include "alur.cpp"
using namespace std;

struct PlayerStats {
    int hp = 100;
    int attack = 25;
    int magic = 25;
    int counter = 25;
    int evade = 25;
    int skillPoint = 10;
    int exp = 0;
    int level = 1;
    int stage = 1;
};

// Upgrade Stat Tree
struct UpgradeNode {
    string statName;
    int level;
    int bonusValue;
    bool unlocked;
    UpgradeNode* next;
};

UpgradeNode* createNextNode(UpgradeNode* prev) {
    int nextLevel = prev->level + 1;
    int bonus = (int)(prev->bonusValue * 1.5);
    UpgradeNode* newNode = new UpgradeNode{prev->statName, nextLevel, bonus, false, nullptr};
    prev->next = newNode;
    return newNode;
}

UpgradeNode* buildStatTree(string statName, int baseBonus) {
    return new UpgradeNode{statName, 1, baseBonus, false, nullptr};
}

void upgradeFromTree(PlayerStats& player, UpgradeNode* node) {
    if (player.skillPoint <= 0) {
        cout << "Skill point tidak cukup.\n\n";
        return;
    }
    while (node->unlocked) {
        if (node->next == nullptr) {
            node = createNextNode(node);
        } else {
            node = node->next;
        }
    }
    node->unlocked = true;
    player.skillPoint--;
    if (node->statName == "hp") player.hp += node->bonusValue;
    else if (node->statName == "attack") player.attack += node->bonusValue;
    else if (node->statName == "magic") player.magic += node->bonusValue;
    else if (node->statName == "counter") player.counter += node->bonusValue;
    else if (node->statName == "evade") player.evade += node->bonusValue;

    cout << "Upgrade " << node->statName << " Lv" << node->level << " berhasil! +" << node->bonusValue << endl << endl;
}

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

// Inventory dengan stack
stack<string> inventoryStack;

void tambahItemKeInventory(const string& item) {
    inventoryStack.push(item);
    cout << item << " ditambahkan ke inventory.\n\n";
}

void tampilkanInventory(stack<string> s) {
    if (s.empty()) {
        cout << "Inventory kosong.\n\n";
        return;
    }
    cout << "Inventory:\n";
    int idx = s.size();
    stack<string> temp;
    while (!s.empty()) {
        cout << idx-- << ". " << s.top() << "\n";
        temp.push(s.top());
        s.pop();
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

    cout << "Pilih nomor item yang ingin digunakan: ";
    int pilih;
    cin >> pilih;
    cout << endl;

    if (pilih < 1 || pilih > (int)tempStack.size()) {
        cout << "Pilihan tidak valid.\n\n";
        return;
    }

    // Cari item yang dipilih
    stack<string> newStack;
    string selectedItem;
    int target = (int)tempStack.size() - pilih;

    for (int i = 0; i < target; ++i) {
        newStack.push(inventoryStack.top());
        inventoryStack.pop();
    }

    selectedItem = inventoryStack.top();
    inventoryStack.pop(); // hapus item dari stack asli

    while (!newStack.empty()) {
        inventoryStack.push(newStack.top());
        newStack.pop();
    }

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
    const int expThreshold = 100;
    while (player.exp >= expThreshold) {
        player.exp -= expThreshold;
        player.level++;
        player.skillPoint += 1; // misal dapat skill point tiap naik level
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


int main() {
    PlayerStats player;

    // Inisialisasi stat tree
    UpgradeNode* hpTree = buildStatTree("hp", 10);
    UpgradeNode* attackTree = buildStatTree("attack", 5);
    UpgradeNode* magicTree = buildStatTree("magic", 5);
    UpgradeNode* counterTree = buildStatTree("counter", 5);
    UpgradeNode* evadeTree = buildStatTree("evade", 5);

    // Isi inventory awal
    tambahItemKeInventory("Magic Poison");
    tambahItemKeInventory("Healing Poison");
    tambahItemKeInventory("Buff Poison");

    string pilihan;

    while (true) {
        tampilkanStats(player);
        cout << "\n------------------------\n";
        cout << "Pilih aksi:\n";
        cout << "1. Upgrade stat (hp/attack/magic/counter/evade)\n";
        cout << "2. Pakai item inventory\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == "1") {
            cout << "Pilih stat untuk upgrade (hp/attack/magic/counter/evade): ";
            cin >> pilihan;
            cout << endl;
            if (pilihan == "hp") upgradeFromTree(player, hpTree);
            else if (pilihan == "attack") upgradeFromTree(player, attackTree);
            else if (pilihan == "magic") upgradeFromTree(player, magicTree);
            else if (pilihan == "counter") upgradeFromTree(player, counterTree);
            else if (pilihan == "evade") upgradeFromTree(player, evadeTree);
            else cout << "Stat tidak dikenali.\n\n";
        } 
        else if (pilihan == "2") {
            useInventoryItem(player);
        } 
        else if (pilihan == "3") {
            cout << "Keluar dari program.\n";
            break;
        } 
        else {
            cout << "Pilihan tidak dikenali.\n\n";
        }

        // Efek poison buff ke musuh setiap giliran
        if (poisonBuffTurns > 0) {
            cout << "Musuh terkena poison damage " << poisonDamagePerTurn << " HP.\n";
            poisonBuffTurns--;
            if (poisonBuffTurns == 0) cout << "Buff poison pada musuh habis.\n";
            cout << endl;
        }
    }

    return 0;
}
