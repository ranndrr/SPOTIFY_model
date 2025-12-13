#include "SPOTIFY_HEAD.h"
#include <iostream>

using namespace std;

void adminMenu(libraryList &L, Playlist &p);
void userMenu(libraryList &L, Playlist &P);

int main() {
    libraryList L;
    createLibraryList(L);
    Playlist P;
    createPlaylist(P);

    // ===== ARRAY DATA LAGU ===== //
    infotype songs[] = {
        {1, "Lover", "Taylor_Swift", "Lover", "Pop", 2019},
        {2, "Blinding_Lights", "The_Weeknd", "After_Hours", "Synthwave", 2020},
        {3, "Shape_of_You", "Ed_Sheeran", "÷_(Divide)", "Pop", 2017},
        {4, "Levitating", "Dua_Lipa", "Future_Nostalgia", "Disco-pop", 2020},
        {5, "Someone_Like_You", "Adele", "21", "Soul", 2011},
        {6, "Bad_Habits", "Ed_Sheeran", "=", "Pop", 2021},
        {7, "Circles", "Post_Malone", "Hollywood's_Bleeding", "Pop_Rock", 2019},
        {8, "Drivers_License", "Olivia_Rodrigo", "Sour", "Pop", 2021},
        {9, "Peaches", "Justin_Bieber", "Justice", "R&B", 2021},
        {10, "Uptown_Funk", "Mark_Ronson_ft._Bruno_Mars", "Uptown_Special", "Funk", 2014}
    };
    int n = sizeof(songs) / sizeof(songs[0]);

    // ===== MASUKKAN KE LIBRARY ===== //
    for (int i = 0; i < n; i++) {
        adrLibrary p = createLibraryElemen(songs[i]);
        inputSongToLibrary(L, p);
    }

    // ===== PLAYLIST AWAL ===== //
    adrPlaylist NP1 = makePlaylistNode("Pop");
    insertLastPlaylist(P, NP1);

    adrPlaylist NP2 = makePlaylistNode("Funk");
    insertLastPlaylist(P, NP2);

    for (int i = 0; i < n; i++) {

    // Cari node lagu di library berdasarkan judul lagu
    adrLibrary libSong = searchSong(L, songs[i].title);

    // ====== MASUKKAN KE PLAYLIST POP ====== //
        if (songs[i].genre == "Pop") {
            adrPlaylist popList = searchPlaylist(P, "Pop");
            if (popList != NULL && libSong != NULL) {
                adrSong S = createElemenSongToPlaylist(libSong);
                addSongToPlaylist(popList, S);
            }
        }

    // ====== MASUKKAN KE PLAYLIST FUNK ====== //
        if (songs[i].genre == "Funk") {
            adrPlaylist funkList = searchPlaylist(P, "Funk");
            if (funkList != NULL && libSong != NULL) {
                adrSong S = createElemenSongToPlaylist(libSong);
                addSongToPlaylist(funkList, S);
            }
        }
}


    // ===== CETAK LIBRARY ===== //
    cout << "=== MENAMPILKAN ISI DARI LIBRARY ===" << endl;
    printSongFromLibrary(L);

    // ===== TAMPILAN MENU UTAMA ===== //
    int pilih;

    while (true) {
        cout << "\n============================\n";
        cout << "      MENU UTAMA\n";
        cout << "============================\n";
        cout << "1. Admin\n";   // CLEAR
        cout << "2. User\n";    // CLEAR
        cout << "3. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;
        if (pilih == 1) {
            adminMenu(L, P);
        } else if (pilih == 2) {
            userMenu(L, P);
        } else if (pilih == 3) {
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
    cout << "\nProgram selesai.\n";
    return 0;
}

void adminMenu(libraryList &L, Playlist &P) {
    int pilih;
    while (true) {
        cout << "\n====== ADMIN MENU ======\n";
        cout << "1. Tambah Lagu ke Library\n"; // CLEAR
        cout << "2. Lihat Semua Lagu di Library\n"; // CLEAR
        cout << "3. Hapus Lagu dari Library\n"; // CLEAR
        cout << "4. Update Lagu di Library\n"; // CLEAR
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            infotype x;
            cout << "Masukkan ID: ";
            cin >> x.id;
            cout << "Judul: ";
            cin >> x.title;
            cout << "Artist: ";
            cin >> x.artist;
            cout << "Album: ";
            cin >> x.album;
            cout << "Genre: ";
            cin >> x.genre;
            cout << "Tahun: ";
            cin >> x.year;

            adrLibrary p = createLibraryElemen(x);
            inputSongToLibrary(L, p);

            cout << "Lagu berhasil ditambahkan.\n";

        } else if (pilih == 2) {
            cout << "\n=== LIST LAGU DI LIBRARY ===\n";
            printSongFromLibrary(L);

        } else if (pilih == 3) {
            string title;
            cout << "Masukkan judul lagu yang ingin dihapus: ";
            cin >> title;

            // CEK APAKAH ADA DI LIBRARY
            adrLibrary p = searchSong(L, title);
            if (p == nullptr) {
                cout << "Lagu tidak ditemukan di library.\n";
            } else {

                // HAPUS DARI LIBRARY
               // 1. Hapus dari semua playlist
                deleteSongFromAllPlaylist(P, title);

                // 2. Baru hapus dari library
                deleteSongFromLibrary(L, title);
            }

        } else if (pilih == 4) {
            string title;
            cout << "Masukkan judul lagu yang ingin diupdate: ";
            cin >> title;

            adrLibrary p = searchSong(L, title);
            if (p == nullptr) {
                cout << "Lagu tidak ditemukan.\n";
            } else {
                string oldTitle = p->info.title;

                cout << "Judul baru: ";
                cin >> p->info.title;
                cout << "Artist baru: ";
                cin >> p->info.artist;
                cout << "Album baru: ";
                cin >> p->info.album;
                cout << "Genre baru: ";
                cin >> p->info.genre;
                cout << "Tahun baru: ";
                cin >> p->info.year;

                updateSongInAllPlaylist(P, oldTitle, p->info);

                cout << "Lagu berhasil diupdate & semua playlist.\n";
            }

        } else if (pilih == 5) {
            break;

        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
}

void userMenu(libraryList &L, Playlist &P) {
    int pilih;
    adrPlaylist currentPlaylist = nullptr;
    adrSong currentSong = nullptr;

    while (true) {
        cout << "\n====== USER MENU ======\n";
        cout << "1. Membuat Playlist baru\n";
        cout << "2. Menambahkan Lagu pada Playlist tertentu\n";
        cout << "3. Menghapus Lagu pada Playlist tertentu\n";
        cout << "4. Lihat Playlist\n";
        cout << "5. Putar Playlist\n";
        cout << "6. Next Lagu\n";
        cout << "7. Prev Lagu\n";
        cout << "8. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            string title;
            cout << "Masukan judul Playlist: ";
            cin >> title;
            adrPlaylist NP = makePlaylistNode(title);
            insertLastPlaylist(P, NP);
            cout << "Playlist berhasil ditambahkan.\n";

        } else if (pilih == 2) {
            string playlistName, titleSong;
            cout << "Nama Playlist: ";
            cin >> playlistName;
            cout << "Judul Lagu yang ingin ditambahkan: ";
            cin >> titleSong;

            adrPlaylist pl = searchPlaylist(P, playlistName);
            adrLibrary lg = searchSong(L, titleSong);

            if (pl != nullptr && lg != nullptr) {
                adrSong S = createElemenSongToPlaylist(lg);
                addSongToPlaylist(pl, S);
                cout << "Lagu berhasil ditambahkan ke playlist.\n";
            } else {
                cout << "Playlist atau Lagu tidak ditemukan.\n";
            }

        } else if (pilih == 3) {
            string playlistName, titleSong;
            cout << "Nama Playlist: ";
            cin >> playlistName;
            cout << "Judul Lagu yang ingin dihapuskan: ";
            cin >> titleSong;

            adrPlaylist pl = searchPlaylist(P, playlistName);
            if (pl == nullptr) {
                cout << "Playlist tidak ditemukan.\n";
                continue;
            }

            deleteSongFromPlaylist(pl, titleSong);
            cout << "Lagu berhasil dihapus dari playlist.\n";

        } else if (pilih == 4) {
            int pilihPlaylist;
            cout << "\n==== MENU PLAYLIST ====\n";
            cout << "1. Tampilkan Playlist tertentu\n";
            cout << "2. Tampilkan semua Playlist & semua lagu\n";
            cout << "3. Kembali\n";
            cout << "Pilih: ";
            cin >> pilihPlaylist;

            if (pilihPlaylist == 1) {
                string title;
                cout << "Masukan judul playlist: ";
                cin >> title;
                printPlaylistByTittle(P, title);
            } else if (pilihPlaylist == 2) {
                printAllPlaylistAndSongs(P);
            }

        } else if (pilih == 5) {
            string playlistName;
            cout << "Nama Playlist: ";
            cin >> playlistName;

            currentPlaylist = searchPlaylist(P, playlistName);
            if (currentPlaylist != nullptr && currentPlaylist->firstSong != nullptr) {
                currentSong = currentPlaylist->firstSong;
                cout << "Memutar: " << currentSong->song->info.title << endl;
            } else {
                cout << "Playlist kosong / tidak ditemukan.\n";
            }

        } else if (pilih == 6) {
            if (currentSong == nullptr) {
                cout << "Belum ada lagu yang diputar.\n";
            } else {
                adrSong next = getNextInPlaylist(currentPlaylist, currentSong);
                if (next != nullptr) {
                    currentSong = next;
                    cout << "Memutar: "
                         << currentSong->song->info.title << endl;
                } else {
                    cout << "Sudah di lagu terakhir.\n";
                }
            }

        } else if (pilih == 7) {
            if (currentPlaylist == nullptr || currentSong == nullptr) {
                cout << "Belum ada playlist yang diputar.\n";
            } else {
                adrSong prev = getPrevInPlaylist(currentPlaylist, currentSong);
                if (prev != nullptr) {
                    currentSong = prev;
                    cout << "Memutar: "
                         << currentSong->song->info.title << endl;
                } else {
                    cout << "Sudah di lagu pertama.\n";
                }
            }

        } else if (pilih == 8) {
            break;

        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }
}


