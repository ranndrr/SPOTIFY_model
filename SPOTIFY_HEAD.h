#ifndef SPOTIFY_HEAD_H_INCLUDED
#define SPOTIFY_HEAD_H_INCLUDED

#include <string>
using namespace std;

// ===== STRUCT DATA =====
struct record {
    int id;
    string title;
    string artist;
    string album;
    string genre;
    int year;
};
};

// ===== STRUCT NODE =====
typedef struct elemenSong* adrSong;

struct elemenSong {
    record info;
    adrSong next;
    adrSong prev;
};

// ===== STRUCT LIST =====
struct songList {
    adrSong first;
    adrSong last;
};

// ===== PROTOTYPE FUNCTION/PROCEDURE =====
void createSongList(songList &S);
adrSong makeSongElemen(record x);
bool isEmptySongList(songList S);
adrSong searchSong(songList &S, string title);
void inputSongToSongList(songList &S, adrSong p);
void deleteSongFromSongList(songList &S, string title);
void printSongList(songList S);

// ------------------------------------------ //

typedef struct elemenLibrary* adrLibrary;

struct libraryList {
    record info;
    adrLibrary first;
};

#endif // SPOTIFY_HEAD_H_INCLUDED
