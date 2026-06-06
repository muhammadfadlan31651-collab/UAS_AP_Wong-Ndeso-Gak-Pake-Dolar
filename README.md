# 🖥️ UAS LAB Algoritma dan Pemrograman 

# Wong-Ndeso-Gak-Pake-Dolar
Repository Collaboration 

Nama-Nama Anggota Kelompok 
1. Muhammad Fadlan Nasution    251401017
2. Ferdinand Macalister        251401077
3. Owen Liandra                251401095
4. Hafifuddin                  251401140
5. Adinda Egia Rehulina Pelawi 251401143

Pembagian Tugas

Sistem Parkir Mall: Fadlan

Game Tebak Kata : Hafifuddin

Manajemen inventaris toko : Adinda

Mineesweeper: Ferdinand

Tebak Negara: Owen

## Deskripsi

Repositori ini merupakan repositori resmi pengumpulan tugas **Ujian Tengah Semester (UAS) Algoritma dan Pemrograman** untuk Kelompok **Wong-Ndeso-Gak-Pake-Dolar**, Semester Genap T.A. 2025/2026. Setiap Anggota  **wajib menyelesaika soal UAS yang sudah diberikan, dan  masing masing mendapatkan bagiannya**.

## Deskripsi Soal/Program.

1. ## Sistem Parkir Mall (Muhammad Fadlan Nasution)
Program ini basically adalah sistem buat ngelola parkir di Mall. Jadi petugas parkir nggak perlu lagi nyatet manual pake kertas, semua dihandle lewat program ini di komputer.
Waktu pertama buka program, petugas diminta masukin nama sama ID dulu, biar ketauan siapa yang lagi jaga. Abis itu baru deh bisa mulai kerjaan.

Fitur utamanya ada 4: 
1. Bisa tambah kendaraan yang masuk
2. lihat daftar mobil yang parkir sekarang
3. prose pembayaran buat yang kendaran yang mau keluar
4. keluar dari program

waktu catat mobil masuk itu sistemnya langsung nyimpen waktu masuknya secara otomatis. Jadi nanti pas bayar, tinggal masukin plat nomornya, biayanya langsung keitung sendiri sesuai berapa lama dia parkir. Nggak perlu hitung manual lagi.
parkiran ini juga ada batasnya itu maksimal 20 mobil. Kalau udah penuh, sistem langsung nolak kalau ada yang mau masuk lagi. Jadi nggak bakal over kapasitas.
Program ini dijalanin lewat CLI alias lewat terminal/command prompt, jadi tampilannya text-based, nggak ada GUI atau tombol-tombol grafis.

2. ## Game Tebak Kata (Hafifuddin)
Program ini adalah game tebak kata berbasis CLI yang langsung bisa dijalanin lewat terminal atau command prompt tanpa perlu install apapun.

Sebelum main, pemain diminta milih dulu tingkat kesulitan: Easy yang ngasih 8 kesempatan salah, Medium 6, atau Hard yang cuma 4. Abis itu sistem bakal pilih satu 
kata rahasia secara acak dari bank kata yang isinya 15 kata, terus tampilinnya sebagai deretan underscore sesuai panjang katanya.

Gameplay-nya simpel, pemain tebak satu huruf per giliran. Kalau hurufnya ada di kata, semua posisi huruf itu langsung kebuka sekaligus. Kalau salah, nyawa 
berkurang satu dan hurufnya masuk ke daftar tebakan salah yang ditampilin di layar. Kalau pemain ngetik huruf yang udah pernah ditebak sebelumnya, sistem kasih 
peringatan tanpa ngurangin nyawa. Layar di-refresh tiap giliran biar tampilannya selalu bersih dan update.

Ada juga fitur Hint, tinggal ketik H dan sistem buka huruf pertama kata rahasia, tapi harganya 1 nyawa dan cuma bisa dipakai sekali per ronde. Kalau berhasil 
menang, pemain dapet skor berdasarkan panjang kata, sisa nyawa, dan tingkat kesulitan yang dipilih — skornya bisa disimpen ke leaderboard yang nyimpen 5 skor 
tertinggi selama satu sesi. Setiap ronde selesai pemain ditanya mau lanjut atau berhenti.

3. ## Sistem Manajemen Inventaris Toko (Adinda Egia Rehulina Pelawi)

Program ini merupakan sistem pengelolaan inventaris barang toko berbasis CLI (Command Line Interface) yang dijalankan melalui terminal atau command prompt. Program ini dibuat untuk membantu pemilik atau petugas toko dalam mengelola data barang yang tersedia di dalam gudang maupun etalase toko secara lebih cepat dan terstruktur dibandingkan pencatatan manual.

Setiap barang yang tersimpan dalam sistem memiliki beberapa informasi penting, yaitu kode barang, nama barang, harga barang, dan jumlah stok yang tersedia. Seluruh data barang disimpan menggunakan struktur data `vector` sehingga data dapat bertambah secara dinamis sesuai kebutuhan pengguna.

Program menyediakan beberapa fitur utama yang dapat diakses melalui menu utama, yaitu:

### Tambah Barang

Pengguna dapat menambahkan data barang baru ke dalam sistem dengan memasukkan kode barang, nama barang, harga barang, dan jumlah stok barang. Sistem akan melakukan validasi untuk memastikan bahwa harga dan stok yang dimasukkan tidak bernilai negatif. Jika data tidak valid, pengguna akan diminta untuk memasukkan ulang data yang benar.

### Tampilkan Semua Barang

Fitur ini digunakan untuk menampilkan seluruh data barang yang telah tersimpan di dalam sistem. Informasi yang ditampilkan meliputi kode barang, nama barang, harga barang, dan stok barang sehingga pengguna dapat melihat kondisi inventaris secara keseluruhan.

### Cari Barang Termahal

Program dapat mencari dan menampilkan barang dengan harga tertinggi dari seluruh data yang tersimpan. Fitur ini membantu pengguna mengetahui barang yang memiliki nilai jual paling tinggi dalam inventaris toko.

### Hitung Total Nilai Inventaris

Sistem dapat menghitung total nilai inventaris yang dimiliki toko dengan cara mengalikan harga setiap barang dengan jumlah stoknya, kemudian menjumlahkan seluruh hasil perhitungan tersebut. Hasil akhir yang ditampilkan menunjukkan total aset barang yang tersedia dalam toko.

### Cek Restock

Program dapat menampilkan daftar barang yang memiliki stok kurang dari 5 unit. Barang-barang tersebut dianggap memiliki stok kritis dan perlu segera dilakukan pemesanan ulang agar tidak kehabisan saat dibutuhkan pelanggan.

### Update Stok

Fitur ini digunakan untuk memperbarui jumlah stok barang yang sudah ada. Pengguna cukup memasukkan kode barang yang ingin diperbarui, kemudian menentukan jumlah stok yang akan ditambahkan atau dikurangi. Pada proses ini digunakan konsep pointer untuk mengakses dan mengubah nilai stok secara langsung.

### Keluar Program

Fitur ini digunakan untuk mengakhiri penggunaan aplikasi. Program akan berhenti berjalan setelah pengguna memilih menu keluar.

Program dirancang menggunakan konsep dasar pemrograman C++ seperti `struct`, `vector`, `function`, `pointer`, percabangan, perulangan, dan validasi input. Dengan adanya sistem ini, proses pengelolaan inventaris barang dapat dilakukan dengan lebih mudah, cepat, dan terorganisir dibandingkan pencatatan secara manual.

4. ## Game Minesweeper (Ferdinand Macalister)
Program ini pada dasarnya adalah game teka-teki logika Minesweeper klasik, tapi semuanya dijalankan full lewat terminal atau command prompt (CLI). Jadi, tidak ada antarmuka grafis atau tombol yang bisa diklik menggunakan mouse; semuanya murni berbasis teks dan dikendalikan lewat ketikan keyboard.

Waktu pertama kali program dibuka, pemain tidak langsung dilempar ke arena permainan. Sistem akan meminta pemain untuk menentukan sendiri seberapa besar ukuran papan dan berapa banyak jumlah ranjau bom yang ingin ditanam. Hal ini membuat permainannya sangat fleksibel karena tingkat kesulitannya bisa diatur secara bebas. Begitu ukuran papan diatur, sistem akan langsung menanam bom secara acak di belakang layar, dan timer otomatis mulai menghitung waktu bermain.

Untuk gameplay utamanya, program ini menyediakan fitur-fitur standar Minesweeper pada umumnya:
- Buka Kotak: Pemain memasukkan angka koordinat baris dan kolom untuk menebak dan membongkar area yang dirasa aman. Kalau area yang ditebak ternyata murni kosong, kotak aman di sekitarnya otomatis ikut terbuka semua.
- Pasang Bendera (Flag): Kalau pemain sudah yakin ada bom di titik tertentu, mereka bisa memasang bendera di koordinat tersebut. Fitur ini berguna untuk mengunci dan menandai area berbahaya agar tidak tidak sengaja terbuka saat lanjut bermain.
- Timer Waktu: Sistem memiliki penghitung waktu di latar belakang yang mencatat durasi total detik yang dihabiskan pemain dari awal mulai sampai mereka berhasil menang.
- Opsi Main Lagi: Setelah satu ronde selesai, entah itu karena berhasil menang atau kalah karena meledak terkena bom, pemain bisa langsung memilih untuk memulai permainan baru lagi tanpa harus menutup dan membuka ulang aplikasi terminalnya.

5. ## Tebak Negara (Owen Liandra)
Program ini pada dasarnya adalah game teka-teki kata bertema geografi, di mana semuanya dijalankan full lewat terminal atau command prompt (CLI). Tidak ada antarmuka grafis atau tombol yang bisa diklik menggunakan mouse; semuanya murni berbasis teks dan dikendalikan sepenuhnya lewat ketikan keyboard.

Waktu pertama kali program dibuka, sistem akan otomatis memuat data dari file sumber terpisah dan mengacak satu nama negara di latar belakang. Sistem kemudian akan mengaburkan identitas negara tersebut dengan menyembunyikan sekitar setengah dari total huruf aslinya dan menggantinya dengan simbol garis bawah (_). Kata yang sudah disensor inilah yang kemudian dilempar ke layar pemain sebagai petunjuk utama.

Untuk gameplay utamanya, program ini menyediakan fitur-fitur interaktif standar pada umumnya:

Tebak Kata (Clue): Pemain menganalisis sisa huruf yang muncul di layar dan mengetikkan tebakan nama negara secara penuh. Sistem pembacaan bersifat case-insensitive, sehingga pemain bebas mengetik menggunakan huruf kapital maupun kecil tanpa memengaruhi hasil penilaian.

Sistem Skor: Program memiliki penghitung nilai di latar belakang. Setiap kali pemain berhasil menebak nama negara dengan tepat, sistem akan memberikan ucapan selamat dan skor akan otomatis bertambah satu poin. Jika tebakan salah, sistem akan memberitahu bahwa jawaban salah dan skor tetap ditahan.

Opsi Main Lagi: Setelah satu ronde tebakan selesai dieksekusi (entah itu berujung benar atau salah), pemain bisa langsung mengetik 'y' untuk meminta soal negara baru lagi atau 'n' untuk mengakhiri permainan, tanpa harus menutup dan membuka ulang aplikasi terminal.


## Screenshot Hasil Masing Masing Program
https://drive.google.com/drive/folders/1zydsKqqFeB4OB2t8SkSq0HpC2yizp_wD?usp=drive_link

## Video Presentasi Melalui Link Youtube 
