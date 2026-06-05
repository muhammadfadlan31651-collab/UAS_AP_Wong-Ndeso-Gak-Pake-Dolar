#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

struct Mobil {
    string platMobil;
    string merkMobil;
    string warnaMobil;
    time_t waktuMasuk;
};

struct Petugas {
    string nama;
    string id;
};
string formatDurasi(double detik) {
    int jam = (int)(detik / 3600);
    int menit = (int)((detik - jam * 3600) / 60);
    int sisa = (int)(detik) % 60;
    return to_string(jam) + " jam " + to_string(menit) + " menit " + to_string(sisa) + " detik";
}
double hitungBiaya(double detikParkir) {
    double jam = detikParkir / 3600.0;
    double biaya = 0;
    if (jam <= 1) {
        biaya = 2000;
    } else {
        biaya = 2000 + (int)(jam) * 1000;
    }
    return biaya;
}
void tambahKendaraan(vector<Mobil*>& daftarMobil, int kapasitas) {
    int jumlah;
    cout << "Masukan jumlah mobil yang akan di parkirkan : ";
    cin >> jumlah;
    cin.ignore(); 

    if ((int)daftarMobil.size() + jumlah > kapasitas) {
        cout << "Maaf, parkiran hanya dapat memuat "<< kapasitas << " mobil " << endl;
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        Mobil* m = new Mobil();
        cout << "\nMobil ke " << (daftarMobil.size() + 1) << endl;

        cout << "Masukkan plat mobil  : ";
        getline(cin, m->platMobil);

        cout << "Masukkan merk mobil  : ";
        getline(cin, m->merkMobil);

        cout << "Masukkan warna mobil : ";
        getline(cin, m->warnaMobil);

        m->waktuMasuk = time(nullptr);
        daftarMobil.push_back(m);
    }
}
void tampilDaftar(vector<Mobil*>& daftarMobil) {
    if (daftarMobil.empty()) {
        cout << "Belum ada kendaraan yang parkir." << endl;
        return;
    }

    cout << "-------- DAFTAR MOBIL YANG SUDAH TERPARKIR --------" << endl;
    time_t sekarang = time(nullptr);
    for (int i = 0; i < (int)daftarMobil.size(); i++) {
        double durasi = difftime(sekarang, daftarMobil[i]->waktuMasuk);
        cout << "Mobil ke-" << (i + 1) << endl;
        cout << "  Plat mobil   : " << daftarMobil[i]->platMobil << endl;
        cout << "  Merk mobil   : " << daftarMobil[i]->merkMobil << endl;
        cout << "  Warna mobil  : " << daftarMobil[i]->warnaMobil << endl;
        cout << "  Waktu parkir : " << formatDurasi(durasi) << endl;
        cout << "----------------------------------------------------" << endl;
    }
}

// ===================== FUNGSI PEMBAYARAN =====================

void pembayaran(vector<Mobil*>& daftarMobil) {
    if (daftarMobil.empty()) {
        cout << "Tidak ada kendaraan yang parkir." << endl;
        return;
    }

    string plat;
    cout << "Masukkan plat mobil yang ingin dibayar : ";
    cin.ignore();
    getline(cin, plat);

    bool ditemukan = false;
    for (int i = 0; i < (int)daftarMobil.size(); i++) {
        if (daftarMobil[i]->platMobil == plat) {
            ditemukan = true;
            time_t sekarang = time(nullptr);
            double durasi = difftime(sekarang, daftarMobil[i]->waktuMasuk);
            double biaya = hitungBiaya(durasi);

            cout << "BIAYA PARKIR : Rp" << fixed << setprecision(0) << biaya << endl;

            delete daftarMobil[i];
            daftarMobil.erase(daftarMobil.begin() + i);
            break;
        }
    }

    if (!ditemukan) {
        cout << "PLAT TIDAK DITEMUKAN !" << endl;
    }
}

// ===================== MAIN =====================

int main() {
    const int KAPASITAS = 20;
    vector<Mobil*> daftarMobil;
    Petugas petugas;

    // Tampilan Awal
    cout << "----------------------- SELAMAT DATANG -----------------------" << endl;
    cout << "               DI PORTAL PARKIR KHUSUS MOBIL" << endl;
    cout << "                        MALL PRIENAL" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "\nKami senang Anda telah hadir." << endl;
    cout << "Sebelum melanjutkan, silahkan masukkan informasi Anda yang akan bertugas hari ini." << endl;

    cout << "\nMasukkan nama : ";
    getline(cin, petugas.nama);
    cout << "Masukkan ID   : ";
    getline(cin, petugas.id);

    cout << "\n---------------------------------------------------------------" << endl;
    cout << "  Nama Petugas : " << petugas.nama << endl;
    cout << "  ID Petugas   : " << petugas.id << endl;
    cout << "\n           TERIMA KASIH ATAS KERJASAMANYA !" << endl;
    cout << "-------------------- SELAMAT BERTUGAS ------------------------" << endl;

    int opsi;
    do {
        cout << "\nSilahkan input opsi berikut dalam bentuk angka." << endl;
        cout << "1. Tambahkan Daftar Kendaraan" << endl;
        cout << "2. Tampilkan Daftar Kendaraan" << endl;
        cout << "3. Pembayaran" << endl;
        cout << "4. Keluar Program" << endl;
        cout << "Masukkan opsi : ";
        cin >> opsi;

        switch (opsi) {
            case 1:
                if ((int)daftarMobil.size() >= KAPASITAS) {
                    cout << "Maaf, parkiran hanya dapat memuat  " << KAPASITAS << " mobil." << endl;
                } else {
                    tambahKendaraan(daftarMobil, KAPASITAS);
                }
                break;
            case 2:
                tampilDaftar(daftarMobil);
                break;
            case 3:
                pembayaran(daftarMobil);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid." << endl;
        }
    } while (opsi != 4);
    for (Mobil* m : daftarMobil) delete m;
    daftarMobil.clear();
    return 0;
}
