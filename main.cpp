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


int main(){
    Player player;
    pair<int, int> posisi = {0, 0};  // Posisi awal
    vertices.insert(posisi);
    vertex_map[posisi] = vertexData(); // Inisialisasi vertex awal

    string input;
    while (true) {
        cout << "Arah (utara/selatan/timur/barat, atau 'keluar' untuk berhenti): ";
        getline(cin, input);
        system("cls");
        transform(input.begin(), input.end(), input.begin(), ::tolower); // Ubah ke huruf kecil

        if (input == "keluar") {break;}
        else if (input == "upgrade") {continue;}
        else if (input == "cari npc") {
            auto result = cari_npc(posisi);
            if (result.first.first == -9999) {
                cout << "NPC tidak ditemukan.\n";
            } else {
                cout << "NPC ditemukan di: (" << result.first.first << ", " << result.first.second << ")\n";
                cout << "Arah yang harus diambil: ";
                for (const auto& arah : result.second) {
                    cout << arah << " ";
                }
                cout << "\n";
            }
            continue;
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
            Tipe tipe_vertex = vertex_map[tujuan].tipe;
            string tipe_str;
            switch (tipe_vertex) {
                case Tipe::EMPTY: tipe_str = "EMPTY"; break;
                case Tipe::MONSTER: tipe_str = "MONSTER"; break;
                case Tipe::NPC: tipe_str = "NPC"; break;
                case Tipe::BONUS: tipe_str = "BONUS"; break;
            }
            cout << "Berpindah ke: (" << posisi.first << ", " << posisi.second << ") dengan tipe: " << tipe_str << "\n";
            if (tipe_vertex == Tipe::NPC) {
                NPCType npc_type = vertex_map[tujuan].npc_type;
                
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
                } else if (npc_type == NPCType::PEDAGANG_KELILING) {
                    npc_pedagang_keliling(player);
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (tipe_vertex == Tipe::MONSTER) {
                const auto& monster_list = vertex_map[tujuan].monsters;
                cout << "Ada " << monster_list.size() << " monster di sini:\n";
                for (size_t i = 0; i < monster_list.size(); ++i) {
                    const MonsterInstance& m = monster_list[i];
                    cout << "Monster " << i + 1 << ": " << m.name << "\n";
                    cout << "  Level: " << m.level << "\n";
                    cout << "  HP: " << m.hp << "\n";
                    cout << "  Attack: " << m.attack << "%\n";
                    cout << "  Magic: " << m.magic << "%\n";
                    cout << "  Counter: " << m.counter << "%\n";
                    cout << "  Evade: " << m.evade << "%\n";
                    cout << "  Damage Attack: " << m.damageAttack << "\n";
                    cout << "  Damage Magic: " << m.damageMagic << "\n";
                    cout << "  Damage Counter: " << m.damageCounter << "\n";
                    cout << "  Evade Chance: " << m.evade << "%\n";
                    cout << "  EXP Reward: " << m.expReward << "\n";
                }
}



    } else {
            cout << "Arah tidak dikenali. Gunakan utara/selatan/timur/barat.\n";
        }
    }

    cout << "\n=== Rangkuman Akhir ===\n";
    tampilkan_edges();
    vertex_map.clear();
    vertices.clear();
    edges.clear();
    return 0;
}