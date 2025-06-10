#include <iostream>
#include "map.cpp"
#include "npc.cpp"
using namespace std;
// #include "battle.cpp"
#include "sistemupgrade.cpp"
#include <map>
#include <set>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <queue>
#include "data.h"
#include "battle.cpp"
#include "alur.h"
#include "help.h"


int main(){
    vertices.insert(posisi);
    vertex_map[posisi] = vertexData(); // Inisialisasi vertex awal 

    string input;

    vertex_map[posisi].tipe = Tipe::STORY;
    vertex_map[posisi].visited = 1;
    showIntro();
    help();
    while (true) {
        checkExpAndLevelUp(player_stats);
        checkLevelAndUpdateStage(player_stats);
        cout << "Masukkan Input (ketik help untuk panduan): ";
        getline(cin, input);
        system("cls");
        transform(input.begin(), input.end(), input.begin(), ::tolower); // Ubah ke huruf kecil

        if (input == "keluar") {break;}
        else if (input == "upgrade") {continue;}
        else if (input == "toko") {
            if (vertex_map[posisi].tipe == Tipe::NPC && vertex_map[posisi].npc_type == NPCType::PEDAGANG_KELILING) {
                npc_pedagang_keliling(player);
            } else {
                 auto result = cari_npc(posisi);
            if (result.first.first == -9999) {
                cout << "NPC tidak ditemukan.\n";
            } else {
                cout << "Pedagang keliling ditemukan di: (" << result.first.first << ", " << result.first.second << ")\n";
                cout << "Arah yang harus diambil: ";
                for (const auto& arah : result.second) {
                    cout << arah << " ";
                }
                cout << "\n";
            }
            continue;
        }

            }
           
        else if (arah.find(input) != arah.end()) {
            pair<int, int> delta = arah[input];
            pair<int, int> tujuan = {posisi.first + delta.first, posisi.second + delta.second};
             // Jika vertex tujuan belum ada di vertex_map, buat vertexData baru
            if (vertex_map.find(tujuan) == vertex_map.end()) {
                vertex_map[tujuan] = vertexData();
            }

            tambah_edge(posisi, tujuan);
            posisi = tujuan;

            // Ambil tipe vertex dan tampilkan
            Tipe tipe_vertex = vertex_map[posisi].tipe;
            string tipe_str;
            switch (tipe_vertex) {
                case Tipe::EMPTY: tipe_str = "EMPTY"; break;
                case Tipe::MONSTER: tipe_str = "MONSTER"; break;
                case Tipe::NPC: tipe_str = "NPC"; break;
                case Tipe::STORY: tipe_str = "STORY"; break;
            }
            cout << "Berpindah ke: (" << posisi.first << ", " << posisi.second << ") dengan tipe: " << tipe_str << "\n";
            if (tipe_vertex == Tipe::NPC) {
                NPCType npc_type = vertex_map[posisi].npc_type;
                if (vertex_map[posisi].visited == 0 && npc_type != NPCType::PEDAGANG_KELILING) {
                if (npc_type == NPCType::GOBLIN) {
                    npc_goblin(player);
                } else if (npc_type == NPCType::WANITA_ANEH) {
                    npc_wanita_aneh(player);
                } else if (npc_type == NPCType::ANAK_KECIL) {
                    npc_anak_kecil(player);
                } else if (npc_type == NPCType::AYAH) {
                    npc_ayah(player);
                } else if (npc_type == NPCType::PRIA_TUA) {
                    npc_pria_tua(player);
                } else if (npc_type == NPCType::DWARFT) {
                    npc_dwarft(player);
                } else if (npc_type == NPCType::BANDIT_YANG_MENYAMAR) {
                    npc_bandit_yang_menyamar(player);
                } 
            }
                else if (npc_type == NPCType::PEDAGANG_KELILING) {
                    npc_pedagang_keliling(player);
                }
                else{
                    switch (npc_type) {
                        case NPCType::GOBLIN: cout << "Kamu sudah bertemu Goblin Pedagang di sini.\n"; break;
                        case NPCType::WANITA_ANEH: cout << "Kamu sudah bertemu Wanita Aneh di sini.\n"; break;
                        case NPCType::ANAK_KECIL: cout << "Kamu sudah bertemu Anak Kecil di sini.\n"; break;
                        case NPCType::AYAH: cout << "Kamu sudah bertemu Ayah di sini.\n"; break;
                        case NPCType::PRIA_TUA: cout << "Kamu sudah bertemu Pria Tua di sini.\n"; break;
                        case NPCType::DWARFT: cout << "Kamu sudah bertemu Dwarf di sini.\n"; break;
                        case NPCType::BANDIT_YANG_MENYAMAR: cout << "Kamu sudah bertemu Bandit yang Menyamari di sini.\n"; break;
                        default: cout << "NPC tidak dikenali.\n"; break;
                    }
                }cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

            if (tipe_vertex == Tipe::MONSTER) {
                if (vertex_map[posisi].defeated == 1){
                    cout << "Kamu sudah mengalahkan monster di sini./n";
                }else{
                const auto& monster_list = vertex_map[posisi].monsters;
                cout << "Ada " << monster_list.size() << " monster di sini:\n";
                // for (size_t i = 0; i < monster_list.size(); ++i) {
                    // int i = 0;
                    // const MonsterInstance& m = monster_list[i];
                    // cout << "Monster " << i + 1 << ": " << m.name << "\n";
                    // cout << "  Level: " << m.level << "\n";
                    // cout << "  HP: " << m.hp << "\n";
                    // cout << "  Attack: " << m.attack << "%\n";
                    // cout << "  Magic: " << m.magic << "%\n";
                    // cout << "  Counter: " << m.counter << "%\n";
                    // cout << "  Evade: " << m.evade << "%\n";
                    // cout << "  Damage Attack: " << m.damageAttack << "\n";
                    // cout << "  Damage Magic: " << m.damageMagic << "\n";
                    // cout << "  Damage Counter: " << m.damageCounter << "\n";
                    // cout << "  Evade Chance: " << m.evade << "%\n";
                    // cout << "  EXP Reward: " << m.expReward << "\n";
                    fightEnemy(player);
                }cin.ignore(numeric_limits<streamsize>::max(), '\n');}


    vertex_map[posisi].visited = 1;
    } 
    else if(input == "help") {
            help();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    else if (input == "stats") {
            tampilkanStats(player_stats);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    else if (input == "upgrade") {
            mainUpgrade();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (input == "inventory") {
            cout << "Inventory:\n";
            if (inventoryStack.empty()) {
                cout << "Inventory kosong.\n";
            } else {
                stack<string> tempStack = inventoryStack;
                while (!tempStack.empty()) {
                    cout << "- " << tempStack.top() << "\n";
                    tempStack.pop();
                }
                cout << "Ketik 'buang' untuk membuang item dari inventory.\n";
                cout << "'Enter' untuk kembali ke menu utama.\n";
                cin >> input;
                input = tolower(input[0]); // Ubah ke huruf kecil
                if (input == "buang"){
                    buangItem();
                }
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    else if(input == "tambahkan exp") {
            cout << "Tambahkan EXP dan Level Up:\n";
            int tambahan_exp;
            cout << "Masukkan jumlah EXP yang ingin ditambahkan: ";
            cin >> tambahan_exp;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            player_stats.exp += tambahan_exp;
            checkExpAndLevelUp(player_stats);
            cout << "EXP sekarang: " << player_stats.exp << ", Level: " << player_stats.level << "\n";
        }
    else {
            cout << "Command tidak diketahui, ketik 'help' untuk list command\n";
        }
    }

    cout << "\n=== Rangkuman Akhir ===\n";
    tampilkan_edges();
    vertex_map.clear();
    vertices.clear();
    edges.clear();
    return 0;
}