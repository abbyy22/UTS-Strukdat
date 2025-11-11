#include "header.h"
#include <iostream>
using namespace std;
//103122400004 Abidah Fatimatuzzahrah

void garis() {
    cout << "========================================" << endl;
}

int main() {
    List L;
    createList(L);

    int pilihan;
    do {
        garis();
        cout << "        Aplikasi My Tel-U Timeline      " << endl;
        garis();
        cout << "1. Tambah Postingan Baru (terurut)" << endl;
        cout << "2. Tampilkan Semua Postingan" << endl;
        cout << "3. Tampilkan Postingan Berdasarkan Username" << endl;
        cout << "4. Tampilkan Postingan Terpopuler" << endl;
        cout << "5. Update Like (Like / Unlike)" << endl;
        cout << "0. Keluar" << endl;
        garis();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            infotype data;
            cout << "Masukkan ID Post     : ";
            cin >> data.id;
            cin.ignore();
            cout << "Masukkan Konten Post : ";
            getline(cin, data.konten);
            cout << "Masukkan Username    : ";
            getline(cin, data.username);
            data.like = 0;

            address P = allocate(data);
            insertSorted(L, P);
            cout << "Postingan berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            printList(L);

        } else if (pilihan == 3) {
            string uname;
            cout << "Masukkan username yang dicari: ";
            cin.ignore();
            getline(cin, uname);
            showByUsername(L, uname);

        } else if (pilihan == 4) {
            showMostLiked(L);

        } else if (pilihan == 5) {
            int id;
            char aksi;
            cout << "Masukkan ID Post: ";
            cin >> id;
            cout << "Like (+) atau Unlike (-): ";
            cin >> aksi;

            if (aksi == '+') updateLike(L, id, true);
            else if (aksi == '-') updateLike(L, id, false);
            else cout << "Input tidak valid." << endl;

        } else if (pilihan == 0) {
            cout << "Keluar dari aplikasi..." << endl;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << endl;
    } while (pilihan != 0);

    return 0;
}
