#include "TebakKata.h"

int main() {
    srand((unsigned int)time(nullptr));

    bool mainLagi = true;

    bersihkanLayar();
    tampilkanJudul();
    cout << "  Selamat datang di Game Tebak Kata!\n";
    cout << "  Tebak kata rahasia huruf demi huruf sebelum nyawamu habis.\n\n";
    cout << "  Tekan Enter untuk mulai...";
    string dummy;
    getline(cin, dummy);

    while (mainLagi) {
        bersihkanLayar();
        tampilkanJudul();

        int    pilihan = pilihKesulitan();
        string namaDifficulty;
        int    nyawaMaks;

        switch (pilihan) {
            case 1:  namaDifficulty = "Easy";   nyawaMaks = 8; break;
            case 2:  namaDifficulty = "Medium";  nyawaMaks = 6; break;
            default: namaDifficulty = "Hard";    nyawaMaks = 4; break;
        }

        jalankanRonde(namaDifficulty, nyawaMaks);

        cout << "  Apakah Anda ingin bermain lagi? (Y/N): ";
        string inputJawab;
        getline(cin, inputJawab);

        char jawab = inputJawab.empty() ? 'n' : tolower(inputJawab[0]);
        if (jawab != 'y') {
            mainLagi = false;
        }
    }

    bersihkanLayar();
    tampilkanJudul();
    cout << "  Terima kasih sudah bermain!\n";
    tampilkanLeaderboard();

    return 0;
}
