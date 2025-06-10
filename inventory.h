#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <stack>
#include <string>
#include "data.h"
using namespace std;

extern stack<string> inventoryStack;
extern const int MAX_INVENTORY_SIZE;

void tambahItemKeInventory(const string& item) {
    if (inventoryStack.size() >= MAX_INVENTORY_SIZE) {
        cout << "Inventory penuh! Tidak bisa menambahkan item.\n\n";
        return;
    }

    inventoryStack.push(item);
    cout << item << " ditambahkan ke inventory.\n\n";
}


void tampilkanInventory(const stack<string>& s) {
    if (s.empty()) {
        cout << "Inventory kosong.\n\n";
        return;
    }

    cout << "Isi Inventory (paling atas ditampilkan pertama):\n";
    stack<string> temp = s;
    int idx = temp.size();
    while (!temp.empty()) {
        cout << idx-- << ". " << temp.top() << "\n";
        temp.pop();
    }
    cout << endl;
}

void buangItem() {
    if (inventoryStack.empty()) {
        cout << "Inventory kosong. Tidak ada item untuk dibuang.\n\n";
        return;
    }

    string dibuang = inventoryStack.top();
    inventoryStack.pop();
    cout << "Item \"" << dibuang << "\" telah dibuang dari inventory.\n\n";
}

bool jualItemDariInventory(const string& item) {
    stack<string> tempStack;
    bool found = false;
    // Pindahkan semua item ke tempStack, kecuali yang ingin dijual (pertama ditemukan)
    while (!inventoryStack.empty()) {
        if (!found && inventoryStack.top() == item) {
            inventoryStack.pop();
            found = true;
            break;
        } else {
            tempStack.push(inventoryStack.top());
            inventoryStack.pop();
        }
    }
    // Kembalikan item lain ke inventoryStack
    while (!tempStack.empty()) {
        inventoryStack.push(tempStack.top());
        tempStack.pop();
    }
    return found;
}



#endif
