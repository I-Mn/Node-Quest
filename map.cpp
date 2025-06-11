#include <iostream>
#include <map>
#include <set>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <queue>
#include "data.h"

using namespace std;
// Tambahkan edge antar dua titik
void tambah_edge(pair<int, int> a, pair<int, int> b) {
    if (a > b) swap(a, b);
    edges.insert({a, b});
    vertices.insert(a);
    vertices.insert(b);
}

// Tampilkan semua edge yang sudah dilewati
void tampilkan_edges() {
    cout << "Edges yang telah dilewati:\n";
    for (const auto& edge : edges) {
        cout << "(" << edge.first.first << "," << edge.first.second << ") <-> "
             << "(" << edge.second.first << "," << edge.second.second << ")\n";
    }
}

// Fungsi cari npc
pair<pair<int, int>, vector<string>> cari_npc(pair<int, int> mulai) {
    queue<pair<int, int>> q;
    map<pair<int, int>, pair<int, int>> parent;
    set<pair<int, int>> visited;

    q.push(mulai);
    visited.insert(mulai);

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if (current != mulai
            && vertex_map[current].tipe == Tipe::NPC
            && vertex_map[current].npc_type == NPCType::PEDAGANG_KELILING)
        {
            // Reconstruct path seperti sebelumnya
            vector<pair<int,int>> path;
            auto step = current;
            while (step != mulai) {
                path.push_back(step);
                step = parent[step];
            }
            reverse(path.begin(), path.end());

            // Konversi ke arah
            vector<string> arah_jalan;
            auto prev = mulai;
            for (auto& p : path) {
                if (p.first  > prev.first)  arah_jalan.push_back("timur");
                else if (p.first  < prev.first)  arah_jalan.push_back("barat");
                else if (p.second > prev.second) arah_jalan.push_back("utara");
                else                              arah_jalan.push_back("selatan");
                prev = p;
            }
            return { current, arah_jalan };
        }

        for (const auto& p : arah) {
            const auto& delta = p.second;
            pair<int, int> tujuan = {current.first + delta.first, current.second + delta.second};
            pair<pair<int, int>, pair<int, int>> edge = (current < tujuan)
                ? make_pair(current, tujuan)
                : make_pair(tujuan, current);

            if (edges.find(edge) != edges.end() && visited.find(tujuan) == visited.end()) {
                q.push(tujuan);
                visited.insert(tujuan);
                parent[tujuan] = current; // pastikan parent diisi untuk semua node yang dikunjungi
            }
        }
    }
    return {{-9999, -9999}, {}};
}

// int utama() {

// }
