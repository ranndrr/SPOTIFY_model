KELOMPOK 11
MUHAMMAD RANDI ANGGARA_103052400071
DWIE AJENG AYU HALMAHERA_103052400043
INDRA DAMARJATI_103052300093

Deskripsi Implementasi Program

Program ini merupakan aplikasi manajemen lagu dan playlist yang dikembangkan menggunakan bahasa C++ dengan menerapkan konsep struktur data Linked List. Sistem dirancang untuk mengelola library lagu, playlist pengguna, serta fitur pemutaran lagu dengan navigasi dan rekomendasi berdasarkan kemiripan data lagu.

1. Manajemen Library Lagu

Library lagu diimplementasikan menggunakan Doubly Linked List, yang memungkinkan traversal dua arah (maju dan mundur) sehingga memudahkan proses penambahan, pencarian, dan penghapusan lagu.

Fungsi-fungsi utama pada library meliputi:

createLibraryList untuk inisialisasi library.

inputSongToLibrary untuk menambahkan lagu ke library.

searchSong dan searchSongByData untuk mencari lagu berdasarkan judul, ID, artis, atau tahun rilis.

deleteSongFromLibrary untuk menghapus lagu dari library.

printSongFromLibrary untuk menampilkan seluruh data lagu.

Setiap lagu disimpan dalam node yang berisi informasi ID, judul, artis, album, genre, dan tahun rilis.

2. Manajemen Playlist

Playlist diimplementasikan menggunakan Doubly Linked List, di mana setiap node playlist dapat menampung beberapa lagu. Setiap playlist memiliki penunjuk ke daftar lagu yang tersimpan di dalamnya.

Fungsi-fungsi playlist meliputi:

createPlaylist untuk inisialisasi playlist.

makePlaylistNode dan insertLastPlaylist untuk membuat dan menambahkan playlist baru.

searchPlaylist untuk mencari playlist berdasarkan nama.

printPlaylistSongs, printPlaylistByTittle, dan printAllPlaylistAndSongs untuk menampilkan playlist beserta lagu-lagunya.

3. Pengelolaan Lagu dalam Playlist

Daftar lagu dalam playlist diimplementasikan menggunakan Singly Linked List, di mana setiap node lagu berisi pointer ke lagu yang ada di library.

Fitur yang disediakan:

createElemenSongToPlaylist untuk menambahkan referensi lagu ke playlist.

addSongToPlaylist untuk memasukkan lagu ke dalam playlist.

deleteSongFromPlaylist untuk menghapus lagu dari playlist tertentu.

Pendekatan ini mencegah duplikasi data lagu karena playlist hanya menyimpan referensi ke lagu di library.

4. Fitur Khusus Admin

Program menyediakan fitur admin untuk menjaga konsistensi data antara library dan playlist, antara lain:

deleteSongFromAllPlaylist untuk menghapus lagu tertentu dari seluruh playlist ketika lagu tersebut dihapus dari library.

updateSongInAllPlaylist untuk memperbarui data lagu pada semua playlist jika terjadi perubahan informasi lagu di library.

5. Fitur Pemutaran Lagu

Untuk mendukung proses pemutaran lagu, program menyediakan navigasi:

getNextInPlaylist untuk memutar lagu berikutnya dalam playlist.

getPrevInPlaylist untuk memutar lagu sebelumnya dalam playlist.

Navigasi ini mengikuti urutan lagu yang tersimpan di dalam playlist.

6. Rekomendasi Lagu Berdasarkan Kemiripan

Jika pemutaran lagu dilakukan di luar playlist, sistem akan mencari lagu yang mirip menggunakan fungsi getSimilarSong. Proses pencarian kemiripan dilakukan secara berurutan berdasarkan:

Genre yang sama

Artis yang sama

Lagu pertama dalam library sebagai alternatif terakhir

Fitur ini memungkinkan pengalaman pemutaran lagu yang lebih relevan bagi pengguna.

7. Kesimpulan

Dengan memanfaatkan Doubly Linked List dan Singly Linked List, program ini mampu mengelola data lagu dan playlist secara efisien. Struktur data yang digunakan mendukung fleksibilitas dalam manipulasi data serta menjaga konsistensi antara library dan playlist, sehingga aplikasi dapat berjalan sesuai dengan kebutuhan sistem manajemen lagu sederhana.
