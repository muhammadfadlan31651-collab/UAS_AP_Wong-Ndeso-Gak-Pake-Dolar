#include "TebakKata.h"

const string BANK_KATA[JUMLAH_KATA] = {
    "komputer", "algoritma", "pemrograman", "jaringan", "database",
    "variabel", "fungsi", "rekursif", "pointer", "struktur",
    "antarmuka", "enkripsi", "browser", "keyboard", "monitor"
};

EntriSkor leaderboard[MAKS_LEADERBOARD];
int       jumlahEntri = 0;

void bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void tampilkanJudul() {
    cout << "+----------------------------------------------+\n";
    cout << "|          === GAME TEBAK KATA ===             |\n";
    cout << "|       Dibuat oleh Nisa - Semester 2          |\n";
    cout << "+----------------------------------------------+\n\n";
}

int pilihKesulitan() {
    int pilihan = 0;
    cout << "Pilih Tingkat Kesulitan:\n";
    cout << "  1. Easy   (8 kesalahan)\n";
    cout << "  2. Medium (6 kesalahan)\n";
    cout << "  3. Hard   (4 kesalahan)\n";
    cout << "Pilihan [1-3]: ";

    while (!(cin >> pilihan) || pilihan < 1 || pilihan > 3) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid. Pilih 1, 2, atau 3: ";
    }
    cin.ignore(1000, '\n');
    return pilihan;
}

void inisialisasiGame(KataGame* game, const string& kata, int nyawa) {
    game->kataAsli      = kata;
    game->sisaNyawa     = nyawa;
    game->jumlahSalah   = 0;
    game->hintDipakai   = false;
    memset(game->tebakanSalah, 0, sizeof(game->tebakanSalah));
    game->statusTebakan = string(kata.size(), '_');
}

bool sudahDitebak(KataGame* game, char huruf) {
    for (size_t i = 0; i < game->kataAsli.size(); i++) {
        if (game->kataAsli[i] == huruf && game->statusTebakan[i] == huruf)
            return true;
    }
    for (int i = 0; i < game->jumlahSalah; i++) {
        if (game->tebakanSalah[i] == huruf)
            return true;
    }
    return false;
}

void prosesTebakanBenar(KataGame* game, char huruf) {
    for (size_t i = 0; i < game->kataAsli.size(); i++) {
        if (game->kataAsli[i] == huruf)
            game->statusTebakan[i] = huruf;
    }
}

void prosesTebakanSalah(KataGame* game, char huruf) {
    game->tebakanSalah[game->jumlahSalah++] = huruf;
    game->sisaNyawa--;
}

bool cekMenang(KataGame* game) {
    return game->statusTebakan == game->kataAsli;
}

void tampilkanStatus(KataGame* game, const string& kesulitan) {
    bersihkanLayar();
    tampilkanJudul();

    cout << "  Kesulitan : " << kesulitan << "\n";
    cout << "  Nyawa     : ";
    for (int i = 0; i < game->sisaNyawa; i++) cout << "* ";
    cout << "\n\n";

    cout << "  Kata      : ";
    for (char c : game->statusTebakan) cout << c << " ";
    cout << "\n";

    cout << "  Salah     : ";
    if (game->jumlahSalah == 0) {
        cout << "(belum ada)";
    } else {
        for (int i = 0; i < game->jumlahSalah; i++) {
            cout << (char)toupper(game->tebakanSalah[i]);
            if (i < game->jumlahSalah - 1) cout << ", ";
        }
    }
    cout << "\n\n";

    if (!game->hintDipakai)
        cout << "  [H] Gunakan Hint (korbankan 1 nyawa)\n";
    cout << "------------------------------------------------\n";
}

void tampilkanHasilAkhir(KataGame* game, bool menang) {
    bersihkanLayar();
    tampilkanJudul();
    if (menang) {
        cout << "  [MENANG] Selamat! Kamu berhasil menebak kata!\n\n";
    } else {
        cout << "  [KALAH] Nyawa habis!\n";
        cout << "  Kata yang benar adalah: ";
        for (char c : game->kataAsli) cout << (char)toupper(c) << " ";
        cout << "\n\n";
    }
}

int hitungSkor(KataGame* game, int nyawaMaks) {
    int skorDasar        = (int)game->kataAsli.size() * 10;
    int bonusNyawa       = game->sisaNyawa * 5;
    int penaltiKesulitan = (10 - nyawaMaks);
    return (skorDasar + bonusNyawa) * (penaltiKesulitan + 1);
}

void simpanSkor(const string& nama, int skor, const string& kesulitan) {
    if (jumlahEntri < MAKS_LEADERBOARD) {
        leaderboard[jumlahEntri++] = {nama, skor, kesulitan};
    } else {
        int idxMin = 0;
        for (int i = 1; i < MAKS_LEADERBOARD; i++) {
            if (leaderboard[i].skor < leaderboard[idxMin].skor)
                idxMin = i;
        }
        if (skor > leaderboard[idxMin].skor)
            leaderboard[idxMin] = {nama, skor, kesulitan};
    }
    for (int i = 0; i < jumlahEntri - 1; i++) {
        for (int j = 0; j < jumlahEntri - i - 1; j++) {
            if (leaderboard[j].skor < leaderboard[j + 1].skor)
                swap(leaderboard[j], leaderboard[j + 1]);
        }
    }
}

void tampilkanLeaderboard() {
    cout << "\n+----------------------------------------------+\n";
    cout << "|              === LEADERBOARD ===             |\n";
    cout << "+----------------------------------------------+\n";
    if (jumlahEntri == 0) {
        cout << "|  (Belum ada skor tersimpan)                  |\n";
    } else {
        for (int i = 0; i < jumlahEntri; i++) {
            cout << "|  " << i + 1 << ". " << leaderboard[i].nama;
            int pad = 20 - (int)leaderboard[i].nama.size();
            for (int s = 0; s < pad; s++) cout << " ";
            cout << leaderboard[i].skor << " pts"
                 << "  [" << leaderboard[i].kesulitan << "]\n";
        }
    }
    cout << "+----------------------------------------------+\n\n";
}

void gunakanHint(KataGame* game) {
    if (game->hintDipakai) {
        cout << "  [!] Hint sudah dipakai di ronde ini!\n";
        return;
    }
    if (game->sisaNyawa <= 1) {
        cout << "  [!] Nyawa tidak cukup untuk menggunakan hint!\n";
        return;
    }
    char hurufPertama = game->kataAsli[0];
    game->hintDipakai = true;
    game->sisaNyawa--;
    prosesTebakanBenar(game, hurufPertama);
    cout << "  [HINT] Huruf pertama adalah '"
         << (char)toupper(hurufPertama) << "'. (-1 nyawa)\n";
}

void jalankanRonde(const string& kesulitan, int nyawaMaks) {
    int idxKata = rand() % JUMLAH_KATA;

    KataGame game;
    inisialisasiGame(&game, BANK_KATA[idxKata], nyawaMaks);

    bool selesai = false;

    while (!selesai) {
        tampilkanStatus(&game, kesulitan);

        cout << "  Tebak huruf";
        if (!game.hintDipakai) cout << " (atau ketik H untuk hint)";
        cout << ": ";

        string input;
        getline(cin, input);

        if (input.empty()) {
            cout << "  [!] Input tidak boleh kosong!\n";
            continue;
        }

        if (input.size() == 1 && tolower(input[0]) == 'h' && !game.hintDipakai) {
            gunakanHint(&game);
            cout << "  Tekan Enter untuk melanjutkan...";
            getline(cin, input);
            if (cekMenang(&game) || game.sisaNyawa <= 0) selesai = true;
            continue;
        }

        if (input.size() != 1 || !isalpha(input[0])) {
            cout << "  [!] Masukkan satu huruf yang valid!\n";
            cout << "  Tekan Enter...";
            getline(cin, input);
            continue;
        }

        char huruf = tolower(input[0]);

        if (sudahDitebak(&game, huruf)) {
            cout << "  [!] Huruf '" << (char)toupper(huruf)
                 << "' sudah pernah ditebak! Coba huruf lain.\n";
            cout << "  Tekan Enter...";
            getline(cin, input);
            continue;
        }

        if (game.kataAsli.find(huruf) != string::npos) {
            prosesTebakanBenar(&game, huruf);
            if (cekMenang(&game)) selesai = true;
        } else {
            prosesTebakanSalah(&game, huruf);
            if (game.sisaNyawa <= 0) selesai = true;
        }
    }

    bool menang = cekMenang(&game);
    tampilkanHasilAkhir(&game, menang);

    if (menang) {
        int skor = hitungSkor(&game, nyawaMaks);
        cout << "  Skor kamu: " << skor << " poin\n\n";
        cout << "  Masukkan namamu untuk leaderboard: ";
        string nama;
        getline(cin, nama);
        if (nama.empty()) nama = "Anonim";
        simpanSkor(nama, skor, kesulitan);
    }

    tampilkanLeaderboard();
}
