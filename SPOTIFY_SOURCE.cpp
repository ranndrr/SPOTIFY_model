#include "SPOTIFY_HEAD.h"
#include <iostream>

using namespace std;

// ================= LIBRARY ================= //

void createLibraryList(libraryList &L) {
    L.first = nullptr;
    L.last = nullptr;
}; // CLEAR

bool isEmptyLibrary(libraryList L) {
    return (L.first == nullptr && L.last == nullptr);
}; // CLEAR

adrLibrary createLibraryElemen(infotype x) {
    adrLibrary p = new elemenLibrary;
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}; // CLEAR

adrLibrary searchSong(libraryList &L, string title) {
    adrLibrary p = L.first;
    while (p != nullptr) {
        if (p->info.title == title) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}; // CLEAR

void inputSongToLibrary(libraryList &L, adrLibrary p) {
    if (isEmptyLibrary(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}; // CLEAR

void deleteSongFromLibrary(libraryList &L, string title) {
    if (isEmptyLibrary(L)) {
        cout << "Library kosong.\n";
        return;
    } else {
        adrLibrary p = searchSong(L, title);  // cari node berdasarkan judul
        if (p == nullptr) {
            cout << "Lagu tidak ditemukan di library.\n";
            return;
        } else {
            if (p == L.first && p == L.last) {
                L.first = nullptr;
                L.last = nullptr;
            } else if (p == L.first) {
                L.first = p->next;
                L.first->prev = nullptr;
            } else if (p == L.last) {
                L.last = p->prev;
                L.last->next = nullptr;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p; // hapus node
        }
    }
}; // CLEAR

void printSongFromLibrary(libraryList L) {
    adrLibrary p = L.first;

    cout << endl;
    while (p != nullptr) {
        cout << "ID     : " << p->info.id << endl;
        cout << "Title  : " << p->info.title << endl;
        cout << "Artist : " << p->info.artist << endl;
        cout << "Album  : " << p->info.album << endl;
        cout << "Genre  : " << p->info.genre << endl;
        cout << "Year   : " << p->info.year << endl;
        cout << "----------------------" << endl;
        p = p->next;
    }
}; // CLEAR

// ================= PLAYLIST ================= //

void createPlaylist(Playlist &P) {
    P.first = nullptr;
    P.last = nullptr;
}; // CLEAR

bool isEmptyPlaylist(Playlist P) {
    return P.first == nullptr;
}; // CLEAR

adrPlaylist makePlaylistNode(string title) {
    adrPlaylist p = new elemenPlaylist;
    p->info = title;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstSong = nullptr;
    return p;
}; // CLEAR

adrPlaylist searchPlaylist(Playlist P, string title) {
    adrPlaylist p = P.first;
    while (p != nullptr) {
        if (p->info == title) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}; // CLEAR

void insertLastPlaylist(Playlist &P, adrPlaylist p) {
    if (isEmptyPlaylist(P)) {
        P.first = p;
        P.last = p;
    } else {
        p->prev = P.last;
        P.last->next = p;
        P.last = p;
    }
}; // CLEAR

void printPlaylistSongs(Playlist P, adrPlaylist p) {
    if (isEmptyPlaylist(P)) {
        cout << "Playlist tidak ditemukan.\n";
        return;
    } else {
        cout << "\n=== Playlist: " << p->info << " ===\n";
        if (p->firstSong == nullptr) {
            cout << "Playlist ini masih kosong.\n";
        } else {
            adrSong s = p->firstSong;
            int no = 1;

            while (s != nullptr) {
                cout << no << ". " << s->song->info.title << ". "
                << s->song->info.artist << endl;
                s = s->next;
                no++;
            }
        }
    }
}; // CLEAR

void printPlaylistByTittle(Playlist P, string title) {
    adrPlaylist p = searchPlaylist(P, title);

    if (p == nullptr) {
        cout << "Playlist: " << title << " tidak ditemukan.\n";
        return;
    } else {
        printPlaylistSongs(P, p);
    }
}; // CLEAR

void printAllPlaylistAndSongs(Playlist P) {
    if (isEmptyPlaylist(P)) {
        cout << "Tidak ada playlist.\n";
        return;
    } else {
        adrPlaylist p = P.first;
        while (p != nullptr) {
            printPlaylistSongs(P, p);
            p = p->next;
        }
    }
}; // CLEAR

// ================= ISI PLAYLIST ================= //

adrSong createElemenSongToPlaylist(adrLibrary song) {
    adrSong p = new elemenSong;
    p->song = song;
    p->next = nullptr;
    return p;
}; // CLEAR

void addSongToPlaylist(adrPlaylist p, adrSong S) {
    if (p == nullptr || S == nullptr) {
        return;
    } else {
        if (p->firstSong == nullptr) {
            p->firstSong = S;
        } else {
            adrSong q = p->firstSong;
            while (q->next != nullptr) {
                q = q->next;
            }
            q->next = S;
        }
    }
}; // CLEAR

void deleteSongFromPlaylist(adrPlaylist p, string titleSong) {
    if (p == nullptr || p->firstSong == nullptr) {
        cout << "Playlist kosong.\n";
        return;
    }

    adrSong q = p->firstSong;
    adrSong prev = nullptr;

    if (q->song->info.title == titleSong) {
        p->firstSong = q->next;
        delete q;
        cout << "Lagu berhasil dihapus dari playlist.\n";
        return;
    }

    while (q != nullptr && q->song->info.title != titleSong) {
        prev = q;
        q = q->next;
    }

    if (q == nullptr) {
        cout << "Lagu tidak ditemukan di playlist.\n";
        return;
    }

    // Putuskan node
    prev->next = q->next;
    delete q;
    cout << "Lagu berhasil dihapus dari playlist.\n";
}; // CLEAR

// ================= FITUR KHUSUS ADMIN ================= //

void deleteSongFromAllPlaylist(Playlist P, string titleSong) {
    adrPlaylist p = P.first;

    // Jika tidak ada playlist sama sekali
    if (p == nullptr) {
        cout << "Tidak ada playlist.\n";
        return;
    }

    // Loop ke semua playlist
    int i = 1;
    while (p != nullptr) {
        cout << "Playlist: " << p->info << " ";
        deleteSongFromPlaylist(p, titleSong);  // HAPUS dari playlist p bila ada
        p = p->next;
        i++;
    }

    cout << "Lagu \"" << titleSong << "\" telah dihapus dari semua playlist.\n";
}; // CLEAR

void updateSongInAllPlaylist(Playlist &P, string oldTitle, infotype newInfo) {
    adrPlaylist pl = P.first;

    while (pl != nullptr) {
        adrSong s = pl->firstSong;

        while (s != nullptr) {
            if (s->song->info.title == oldTitle) {
                s->song->info = newInfo;
        }
        s = s->next;
    }
    pl = pl->next;
    }
}; // CLEAR

// ================= FITUR KHUSUS USER ================= //
adrSong getNextInPlaylist(adrPlaylist P, adrSong current) {
    if (current == nullptr) return nullptr;
    return current->next; // kalau null berarti sudah mentok
}; // CLEAR

adrSong getPrevInPlaylist(adrPlaylist P, adrSong current) {
    if (P == nullptr || P->firstSong == nullptr || current == nullptr)
        return nullptr;

    if (P->firstSong == current) return nullptr; // tidak ada prev

    adrSong q = P->firstSong;
    while (q->next != current) {
        q = q->next;
    }
    return q;
}; // CLEAR


adrLibrary getSimilarSong(libraryList L, adrLibrary last) {
    if (L.first == nullptr || last == nullptr)
        return nullptr;

    adrLibrary p = L.first;

    // 1️⃣ Cari genre yang sama
    while (p != nullptr) {
        if (p != last &&
            p->info.genre == last->info.genre) {
            return p;
        }
        p = p->next;
    }

    // 2️⃣ Jika tidak ada genre sama, cari artist sama
    p = L.first;
    while (p != nullptr) {
        if (p != last &&
            p->info.artist == last->info.artist) {
            return p;
        }
        p = p->next;
    }

    // 3️⃣ Jika tetap tidak ada, kembalikan lagu pertama (fallback)
    if (L.first != last)
        return L.first;

    return nullptr;
}; // CLEAR

adrLibrary searchSongByData(libraryList L, int pilihan) {
    adrLibrary p = L.first;

    int id, year;
    string title, artist;

    // Input berdasarkan pilihan
    if (pilihan == 1) {
        cout << "Masukkan ID lagu: ";
        cin >> id;
    }
    else if (pilihan == 2) {
        cout << "Masukkan judul lagu: ";
        cin >> title;
    }
    else if (pilihan == 3) {
        cout << "Masukkan nama artis: ";
        cin >> artist;
    }
    else if (pilihan == 4) {
        cout << "Masukkan tahun rilis: ";
        cin >> year;
    }

    // Proses pencarian
    while (p != nullptr) {
        if (pilihan == 1 && p->info.id == id) {
            return p;
        }
        else if (pilihan == 2 && p->info.title == title) {
            return p;
        }
        else if (pilihan == 3 && p->info.artist == artist) {
            return p;
        }
        else if (pilihan == 4 && p->info.year == year) {
            return p;
        }
        p = p->next;
    }

    return nullptr;
}; // CLEAR




