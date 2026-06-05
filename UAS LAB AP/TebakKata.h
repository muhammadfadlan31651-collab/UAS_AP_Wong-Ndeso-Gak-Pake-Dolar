#ifndef TEBAK_KATA_H
#define TEBAK_KATA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

const int JUMLAH_KATA      = 15;
const int MAKS_LEADERBOARD = 5;

extern const string BANK_KATA[JUMLAH_KATA];

struct KataGame {
    string kataAsli;
    string statusTebakan;
    int    sisaNyawa;
    char   tebakanSalah[26];
    int    jumlahSalah;
    bool   hintDipakai;
};

struct EntriSkor {
    string nama;
    int    skor;
    string kesulitan;
};

extern EntriSkor leaderboard[MAKS_LEADERBOARD];
extern int       jumlahEntri;

void  bersihkanLayar();
void  tampilkanJudul();
int   pilihKesulitan();
void  inisialisasiGame(KataGame* game, const string& kata, int nyawa);
bool  sudahDitebak(KataGame* game, char huruf);
void  prosesTebakanBenar(KataGame* game, char huruf);
void  prosesTebakanSalah(KataGame* game, char huruf);
bool  cekMenang(KataGame* game);
void  tampilkanStatus(KataGame* game, const string& kesulitan);
void  tampilkanHasilAkhir(KataGame* game, bool menang);
int   hitungSkor(KataGame* game, int nyawaMaks);
void  simpanSkor(const string& nama, int skor, const string& kesulitan);
void  tampilkanLeaderboard();
void  gunakanHint(KataGame* game);
void  jalankanRonde(const string& kesulitan, int nyawaMaks);

#endif
