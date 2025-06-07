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
using namespace std;

// Algoritma Randomizer
std::random_device rd;
std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
int randomizer(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);
    int angka_random = distrib(gen);
    return angka_random;
}

// Data NPC
enum class NPCType { GOBLIN, WANITA_ANEH };

struct Player
{
    int HP = 100;
    int healing_poison = 0;
    int magic_poison = 0;
    int buff_poison = 0;
    int gold = 0;
    int attack = 10;
    int defense = 5;
    int weapon_durability = 100;
    int weapon_max_durability = 100;
    int armor_durability = 100;
    int armor_max_durability = 100;
};
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
}; PlayerStats player_stats;
struct UpgradeNode {
    string statName;
    int level;
    int bonusValue;
    bool unlocked;
    UpgradeNode* next;
};



// Data vertex
enum class Tipe { EMPTY, MONSTER, NPC, BONUS };

// Enum untuk tipe monster
enum class MonsterType {
    BRUTE,
    WARLOCK,
    TRICKSTER,
    PHANTOM,
    SENTINEL,
    HUMANOID,
    BERSERKER,
    HEXER,
    SHADOW,
    TITAN,
    COUNT // supaya tahu jumlah monster
};

// Template untuk monster
struct MonsterTemplate {
    string name;
    int baseHP;
    int baseAttack;
    int baseMagic;
    int baseCounter;
    int baseEvade;
    int damageAttack;
    int damageMagic;
    int damageCounter;
    int baseExp;
    int evadeChance;
};

const MonsterTemplate monster_templates[] = {
    {
        "Slime", 40, 
        20, 10, 20, 50,
        15, 10, 15,
        10, 15
    },
    {
        "Goblin", 50,
        35, 10, 25, 30,
        20, 10, 25,
        20, 25
    },
    {
        "Wolf", 80, 
        50, 5, 20, 25,
        40, 10, 20,
        30, 35
    },
    {
        "Bandit", 90, 
        40, 10, 30, 20,
        35, 15, 30,
        40, 20
    },
    {
        "Mage", 70, 
        15, 55, 10, 20,
        15, 55, 15,
        45, 30
    },
    {
        "Archer", 75, 
        25, 10, 45, 20,
        20, 10, 50,
        55, 45
    },
    {
        "Knight", 130, 
        45, 5, 25, 25,
        50, 10, 25,
        60, 10
    },
    {
        "Assassin", 85, 
        30, 10, 40, 20,
        25, 10, 55,
        70, 60
    },
    {
        "Warlock", 95, 
        10, 50, 15, 25,
        15, 60, 20,
        80, 35
    },
    {
        "Dragon", 300, 
        45, 25, 20, 10,
        60, 35, 25,
        100, 25
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
        attack = tmpl.baseAttack;
        magic = tmpl.baseMagic;
        counter = tmpl.baseCounter;
        evade = tmpl.baseEvade;
        damageAttack = static_cast<int>(tmpl.damageAttack * pow(1.15, lvl - 1));
        damageMagic = static_cast<int>(tmpl.damageMagic * pow(1.15, lvl - 1));
        damageCounter = static_cast<int>(tmpl.damageCounter * pow(1.15, lvl - 1));
        expReward = static_cast<int>(tmpl.baseExp * pow(1.3, level - 1)); // EXP reward berdasarkan level
    }
};
struct vertexData {
    string name;
    int visited = 0;
    Tipe tipe;
    NPCType npc_type;
    vector<MonsterInstance> monsters;

    vertexData() {
        int x;
        int r = 0; // Untuk monster, jumlah monster
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
        else if (x > 60 && x <= 95){
            tipe =  Tipe::NPC;
            npc_type = static_cast<NPCType>(randomizer(0, 1)); // 0 for GOBLIN, 1 for WANITA_ANEH
        } else {
            tipe = Tipe::BONUS;
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

// Menyimpan edge yang telah dilewati (unik dan tidak berarah)
set<pair<pair<int, int>, pair<int, int>>> edges;

// Menyimpan semua koordinat (vertex) yang sudah dikunjungi
set<pair<int, int>> vertices;

map <pair<int, int>, vertexData> vertex_map;

#endif