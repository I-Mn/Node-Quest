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
using namespace std;

// Algoritma Randomizer
std::random_device rd;
std::mt19937 gen(rd());
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
};
struct UpgradeNode {
    string statName;
    int level;
    int bonusValue;
    bool unlocked;
    UpgradeNode* next;
};



// Data vertex
enum class Tipe { EMPTY, MONSTER, NPC, BONUS };

struct vertexData {
    string name;
    int visited = 0;
    int x;
    Tipe tipe;
    NPCType npc_type;

    vertexData() {
        x = randomizer(1,100);
        if (x <= 30){
            tipe = Tipe::EMPTY;
        } else if (x > 30 && x <= 60){
            tipe = Tipe::MONSTER;
        }
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