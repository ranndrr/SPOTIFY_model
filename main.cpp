#include "SPOTIFY_HEAD.h"
#include <iostream>

using namespace std;

int main() {
    songList S;
    createSongList(S);

    // ===== DATA LAGU =====
    record r1 = {1, "Fix_You", "Coldplay", "X&Y", "Rock", 2005};
    record r2 = {2, "Perfect", "Ed Sheeran", "Divide", "Pop", 2017};
    record r3 = {3, "Yellow", "Coldplay", "Parachutes", "Rock", 2000};
    record r4 = {4, "Blinding_Lights", "The Weeknd", "After Hours", "Synthwave", 2020};
    record r5 = {5, "Someone_Like_You", "Adele", "21", "Soul", 2011};

    // ===== INSERT =====
    inputSongToSongList(S, makeSongElemen(r1));
    inputSongToSongList(S, makeSongElemen(r2));
    inputSongToSongList(S, makeSongElemen(r3));
    inputSongToSongList(S, makeSongElemen(r4));

    cout << "=== Daftar Lagu Awal ===" << endl;
    printSongList(S);

    // ===== SEARCH =====
    string cari = "Fix_You";
    adrSong hasil = searchSong(S, cari);

    if (hasil != nullptr) {
        cout << "\nLagu ditemukan: " << hasil->info.title << endl;
    } else {
        cout << "\nLagu tidak ditemukan" << endl;
    }

    // ===== DELETE FIRST =====
    cout << "\nHapus lagu: Lover" << endl;
    deleteSongFromSongList(S, "Lover");
    printSongList(S);

    // ===== DELETE MIDDLE =====
    cout << "\nHapus lagu: Perfect" << endl;
    deleteSongFromSongList(S, "Perfect");
    printSongList(S);

    // ===== DELETE LAST =====
    cout << "\nHapus lagu: Yellow" << endl;
    deleteSongFromSongList(S, "Yellow");
    printSongList(S);

    return 0;
}
