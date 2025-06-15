#include <iostream>
using namespace std;
#include <cmath>
int tambahanA = 1;
int jumlahTambahanA = 200;
int baseTambahanA = 50; // Nilai dasar untuk tambahan A

void PerhitunganA(){
    jumlahTambahanA += (int)(baseTambahanA * pow(1.235, tambahanA-1));
    cout << tambahanA;
    cout << "Jumlah Tambahan A sekarang: " << jumlahTambahanA << endl;
    tambahanA++;
}
int tambahanB = 1;
int jumlahTambahanB = 50;
int baseTambahanB = 50; // Nilai dasar untuk tambahan B
void PerhitunganB(){
    jumlahTambahanB += (int)(baseTambahanB/2 * pow(1.23, tambahanB-1));
    cout << tambahanB;
    cout << "Jumlah Tambahan B sekarang: " << jumlahTambahanB << endl;
    tambahanB++;}

int main() {
    for (int i = 0; i<40; i++){
    PerhitunganA();
    }
    for (int i = 0; i<40; i++){


    PerhitunganB();
    }}


