#include "SPOTIFY_HEAD.h"
#include <iostream>

using namespace std;

// ===== CREATE LIST =====
void createSongList(songList &S) {
    S.first = nullptr;
    S.last = nullptr;
}

// ===== CREATE NODE =====
adrSong makeSongElemen(record x) {
    adrSong p;
    p = new elemenSong;

    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}

// ===== CEK KOSONG =====
bool isEmptySongList(songList S) {
    return (S.first == nullptr && S.last == nullptr);
}

// ===== SEARCH =====
adrSong searchSong(songList &S, string title) {
    adrSong p;
    p = S.first;
    while (p != nullptr) {
        if (p->info.title == title) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// ===== INSERT LAST =====
void inputSongToSongList(songList &S, adrSong p) {
    if (isEmptySongList(S)) {
        S.first = p;
        S.last = p;
    } else {
        p->prev = S.last;
        S.last->next = p;
        S.last = p;
    }
}

// ===== DELETE BY TITLE =====
void deleteSongFromSongList(songList &S, string title) {
    adrSong q;
    q = searchSong(S, title);

    if (isEmptySongList(S) || q == nullptr) {
        return;
    }

    // satu elemen
    if (q == S.first && q == S.last) {
        S.first = nullptr;
        S.last = nullptr;
    }
    // delete first
    else if (q == S.first) {
        S.first = q->next;
        S.first->prev = nullptr;
    }
    // delete last
    else if (q == S.last) {
        S.last = q->prev;
        S.last->next = nullptr;
    }
    // delete middle
    else {
        q->prev->next = q->next;
        q->next->prev = q->prev;
    }

    // lepas pointer (tanpa delete memory)
    q->next = nullptr;
    q->prev = nullptr;
}

// ===== PRINT LIST =====
void printSongList(songList S) {
    adrSong p;
    p = S.first;

    if (p == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    while (p != nullptr) {
        cout << p->info.id << " | "
             << p->info.title << " | "
             << p->info.artist << " | "
             << p->info.genre << " | "
             << p->info.year << endl;
        p = p->next;
    }
}
