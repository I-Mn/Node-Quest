#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <queue>
#include <ctime>
#include <cmath>
#include <stack>
using namespace std;

// Algoritma Randomizer
std::random_device rd;
std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
int randomizer(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);
    int angka_random = distrib(gen);
    return angka_random;
}

#include <cctype>    // untuk tolower

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), [](unsigned char c){
        return tolower(c);
    });
    return result;
}


// Data NPC
enum class NPCType { GOBLIN, WANITA_ANEH, ANAK_KECIL, AYAH, PRIA_TUA, DWARFT, BANDIT_YANG_MENYAMAR, PEDAGANG_KELILING};

struct Player
{
    int HP = 100;
    int gold = 0;
    int weapon_durability = 100;
    int weapon_max_durability = 100;
    int armor_durability = 100;
    int armor_max_durability = 100;
};
    struct PlayerStats {
    int hp = 300;
    int attack = 250;
    int magic = 250;
    int counter = 250;
    int evade = 20;
    int skillPoint = 10;
    int exp = 0;
    int level = 1;
    int stage = 0;
}; PlayerStats player_stats;

struct Upgrade{
    int upgrade_hp = 0;
    int upgrade_attack = 0;
    int upgrade_magic = 0;
    int upgrade_counter = 0;
    int upgrade_evade = 0;

    int baseUpgrade_hp = 100;
    int baseUpgrade_attack = 50;
    int baseUpgrade_magic = 50;
    int baseUpgrade_counter = 50;
    int baseUpgrade_evade = 5;
}; Upgrade upgrade_stats;

// struct UpgradeNode {
//     string statName;
//     int level;
//     int bonusValue;
//     bool unlocked;
//     UpgradeNode* next;
// };



// Data vertex
enum class Tipe { EMPTY, MONSTER, NPC, STORY };

// Enum untuk tipe monster
enum class MonsterType {
    TUNG_TUNG_SAHUR,
    TRALALERO_TRALALA,
    BOMBARDILO_CROCODILO,
    BRBR_PATAPIM,
    BOBORITO_BANDITO,
    BOMBOMBINI_GUZINI,
    COUNT // supaya tahu jumlah monster
};

// Template untuk monster
struct MonsterTemplate {
    string name;
    int baseHP;
    int percAttack;
    int percMagic;
    int percCounter;
    int percEvade;
    int damageAttack;
    int damageMagic;
    int damageCounter;
    int baseExp;
    int evadeChance;
};

const MonsterTemplate monster_templates[] = {
    {
        "Tung Tung Sahur", 60,   // baseHP
        30, 20, 30, 20,          // baseAttack, baseMagic, baseCounter, baseEvade
        25, 15, 20,              // damageAttack, damageMagic, damageCounter
        30, 20                   // baseExp, evadeChance
    },
    {
        "Tralalero Tralala", 80,
        25, 30, 25, 20,
        30, 25, 30,
        50, 25
    },
    {
        "Bombardilo Crocodilo", 100,
        40, 20, 30, 10,
        40, 20, 30,
        70, 15
    },
    {
        "Brbr Patapim", 60,
        35, 15, 35, 15,
        25, 15, 25,
        40, 30
    },
    {
        "Boborito Bandito", 90,
        30, 35, 20, 15,
        30, 35, 20,
        60, 20
    },
    {
        "Bombombini Guzini", 120,
        25, 40, 25, 10,
        35, 45, 25,
        80, 15
    }
};



// Statistik monster
struct MonsterInstance {
    string name;
    int level;
    int hp;
    int attack;
    int magic;
    int counter;
    int evade;
    int damageAttack;
    int damageMagic;
    int damageCounter;
    int expReward; 
    MonsterType type;

    MonsterInstance(MonsterType t, int lvl) {
        const MonsterTemplate& tmpl = monster_templates[static_cast<int>(t)];
        name = tmpl.name;
        type = t;
        level = lvl;
        hp = tmpl.baseHP + lvl * 10;
        attack = tmpl.percAttack;
        magic = tmpl.percMagic;
        counter = tmpl.percCounter;
        evade = tmpl.percEvade;
        damageAttack = static_cast<int>(tmpl.damageAttack * pow(1.15, lvl - 1));
        damageMagic = static_cast<int>(tmpl.damageMagic * pow(1.15, lvl - 1));
        damageCounter = static_cast<int>(tmpl.damageCounter * pow(1.15, lvl - 1));
        expReward = static_cast<int>(tmpl.baseExp * pow(1.3, level - 1)); // EXP reward berdasarkan level
    }
};

//Data Vertex
struct vertexData {
    string name;
    int visited = 0;
    int r = 0; // Untuk monster, jumlah monster
    Tipe tipe;
    NPCType npc_type;
    vector<MonsterInstance> monsters;
    int defeated = 0;

    vertexData() {
        int x;

        int level = 1; // Level monster
        x = randomizer(1,100);
        if (x <= 30){
            tipe = Tipe::EMPTY;
        } else if (x > 30 && x <= 60){
            tipe = Tipe::MONSTER;
            r = randomizer(1, 3);
            int minLevel = max(1, player_stats.level - 2);
            int maxLevel = min(player_stats.level + 3, static_cast<int>(player_stats.level*1.5));
            level = randomizer(minLevel, maxLevel);

            // Pilih tipe monster secara acak
            for (int i = 0; i < r; ++i) {
                MonsterType mtype = static_cast<MonsterType>(randomizer(0, static_cast<int>(MonsterType::COUNT) - 1));
                monsters.emplace_back(mtype, level);
        }}
        else if (x > 60 && x <= 100){
            tipe =  Tipe::NPC;
            npc_type = static_cast<NPCType>(randomizer(0, 7));
        } else {
            tipe = Tipe::STORY;
        }
    }
};

// Map arah mata angin ke perubahan koordinat (delta x, delta y)
map<string, pair<int, int>> arah = {
    {"utara", {0, 1}},
    {"selatan", {0, -1}},
    {"timur", {1, 0}},
    {"barat", {-1, 0}}
};

// Menyimpan posisi saat ini
pair<int, int> posisi = {0, 0};  // Posisi awal

// Menyimpan edge yang telah dilewati (unik dan tidak berarah)
set<pair<pair<int, int>, pair<int, int>>> edges;

// Menyimpan semua koordinat (vertex) yang sudah dikunjungi
set<pair<int, int>> vertices;

map <pair<int, int>, vertexData> vertex_map;

Player player;
// MonsterInstance& enemy = vertex_map[posisi].monsters[0];

// Inventory dengan stack
stack<string> inventoryStack;
const int MAX_INVENTORY_SIZE = 3;
#endif