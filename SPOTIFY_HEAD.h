#ifndef SPOTIFY_HEAD_H_INCLUDED
#define SPOTIFY_HEAD_H_INCLUDED

#include <iostream>
using namespace std;

// ===== TIPE DATA ===== //
struct record {
    int id;
    string title;
    string artist;
    string album;
    string genre;
    int year;
};

typedef record infotype;
// ========================= //

// ===== STRUKTUR DARI LIBRARY ===== //
typedef struct elemenLibrary *adrLibrary;

struct elemenLibrary {
    infotype info;
    adrLibrary next;
    adrLibrary prev;
};

struct libraryList {
    adrLibrary first;
    adrLibrary last;
};
// ========================= //

// ===== STRUKTUR RELASI PLAYLIST KE LAGU ===== //
typedef struct elemenSong *adrSong;

struct elemenSong {
    adrLibrary song;
    adrSong next;
};
// ========================= //

// ===== STRUKTUR DARI PLAYLIST ===== //
typedef struct elemenPlaylist *adrPlaylist;

struct elemenPlaylist {
    string info;
    adrPlaylist next;
    adrPlaylist prev;
    adrSong firstSong;
};

struct Playlist {
    adrPlaylist first;
    adrPlaylist last;
};
// ========================= //

// ===== STRUKTUR PLAY AND STOP ===== //

// ===== FITUR ===== //

// LIBRARY
void createLibraryList(libraryList &L); // CLEAR

bool isEmptyLibrary(libraryList L); // CLEAR

adrLibrary createLibraryElemen(infotype x); // CLEAR

adrLibrary searchSong(libraryList &L, string title); // CLEAR

void inputSongToLibrary(libraryList &L, adrLibrary p); // CLEAR

void deleteSongFromLibrary(libraryList &L, string title); // CLEAR

void printSongFromLibrary(libraryList L); // CLEAR



// PLAYLIST
void createPlaylist(Playlist &P); // CLEAR

bool isEmptyPlaylist(Playlist P);

adrPlaylist makePlaylistNode(string title); // CLEAR

adrPlaylist searchPlaylist(Playlist P, string title); // CLEAR

void insertLastPlaylist(Playlist &P, adrPlaylist p); // CLEAR

void printPlaylistSongs(Playlist P, adrPlaylist p); // CLEAR

void printPlaylistByTittle(Playlist P, string title); // CLEAR

void printAllPlaylistAndSongs(Playlist P); // CLEAR



// ISI PLAYLIST
adrSong createElemenSongToPlaylist(adrLibrary song); // CLEAR

void addSongToPlaylist(adrPlaylist p, adrSong S); // CLEAR

void deleteSongFromAllPlaylist(Playlist P, string titleSong); // CLEAR

// FITUR KHUSUS ADMIN
void deleteSongFromPlaylist(adrPlaylist p, string titleSong);

void updateSongInAllPlaylist(Playlist &P, string oldTitle, infotype newInfo); // CLEAR

// FITUR KHUSUS USER
// DALAM PLAYLIST //
adrSong getNextInPlaylist(adrPlaylist P, adrSong current);

adrSong getPrevInPlaylist(adrPlaylist P, adrSong current);




adrLibrary getSimilarSong(libraryList L, adrLibrary last);
// ========================= //

#endif // SPOTIFY_HEAD_H_INCLUDED
