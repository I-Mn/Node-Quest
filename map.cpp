#include <iostream>
#include <map>
#include <set>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>
#include <queue>

using namespace std;

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


// Algoritma Randomizer
  std::random_device rd;
    std::mt19937 gen(rd());
int randomizer(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);

    int angka_random = distrib(gen);
    return angka_random;
}

// Data vertex
enum class Tipe { EMPTY, MONSTER, NPC, BONUS };

struct vertexData {
    string name;
    int visited = 0;
    int x;
    Tipe tipe;

    vertexData() {
        x = randomizer(1,100);
        if (x <= 55){
            tipe = Tipe::EMPTY;
        } else if (x > 55 && x <= 90){
            tipe = Tipe::MONSTER;
        }
        else if (x > 90 && x <= 99){
            tipe =  Tipe::NPC;
    } else {
            tipe = Tipe::BONUS;
        }
    }
};

map <pair<int, int>, struct vertexData> vertex_map;

// Tambahkan edge antar dua titik, pastikan (a, b) == (b, a)
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
    queue <pair<int, int>> q;
    map <pair<int, int>, pair<int, int>> parent;
    set<pair<int, int>> visited;

    q.push(mulai);
    visited.insert(mulai);

    while (!q.empty()){
        pair<int, int> current  = q.front();
        q.pop();

        if (vertex_map[current].tipe == Tipe::NPC && current != mulai){
            vector<pair<int, int>> path;
            pair<int, int> step = current;
            while (step != mulai) {
                path.push_back(step);
                step = parent[step];
            }
            reverse(path.begin(), path.end());

            vector<string> arah_jalan;
            pair <int, int> prev = mulai;
            for (const auto& pos : path) {
                if (pos.first > prev.first) {
                    arah_jalan.push_back("timur");
                } else if (pos.first < prev.first) {
                    arah_jalan.push_back("barat");
                } else if (pos.second > prev.second) {
                    arah_jalan.push_back("utara");
                } else if (pos.second < prev.second) {
                    arah_jalan.push_back("selatan");
                }
                prev = pos;
            }
            return {current, arah_jalan};
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
                parent[tujuan] = current;
            }

        }
    }
    return {{-9999, -9999}, {}};
}

int main() {
    pair<int, int> posisi = {0, 0};  // Posisi awal
    vertices.insert(posisi);
    vertex_map[posisi] = vertexData(); // Inisialisasi vertex awal

    string input;
    while (true) {
        cout << "Arah (utara/selatan/timur/barat, atau 'keluar' untuk berhenti): ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower); // Ubah ke huruf kecil

        if (input == "keluar") {break;}
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
    system("cls");
    cout << "Berpindah ke: (" << posisi.first << ", " << posisi.second << ") dengan tipe: " << tipe_str << "\n";
    } else {
            cout << "Arah tidak dikenali. Gunakan utara/selatan/timur/barat.\n";
        }
    }

    cout << "\n=== Rangkuman Akhir ===\n";
    tampilkan_edges();
    return 0;
}
