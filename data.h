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
        if (x <= 55){
            tipe = Tipe::EMPTY;
        } else if (x > 55 && x <= 90){
            tipe = Tipe::MONSTER;
        }
        else if (x > 90 && x <= 99){
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