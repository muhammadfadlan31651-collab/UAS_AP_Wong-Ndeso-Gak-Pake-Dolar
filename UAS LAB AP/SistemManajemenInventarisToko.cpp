#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct DataBarang {
    string KodeBarang;
    string NamaBarang;
    double HargaBarang;
    int StokBarang;
};

void KembaliKeMenu() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();

    system("cls");
}
void Menu(){
    cout << "\n===== MENU MANAJEMEN INVENTARIS TOKO =====\n";
    cout << "1. Tambah Barang\n";
    cout << "2. Tampilkan Semua Barang\n";
    cout << "3. Cari Barang Termahal\n";
    cout << "4. Total Nilai Inventaris\n";
    cout << "5. Cek Restock\n";
    cout << "6. Update Stok\n";
    cout << "7. Keluar\n";
}

void TambahBarang(vector<DataBarang>& DaftarBarang) {    
    DataBarang db;

    cout << "Masukkan Kode Barang  : ";
    cin  >> db.KodeBarang;
    cin.ignore();

    cout << "Masukkan Nama Barang  : ";
    getline(cin, db.NamaBarang);

    do {
        cout << "Masukkan Harga Barang : ";
        cin  >> db.HargaBarang;

        if (db.HargaBarang < 0){
            cout << "Harga Tidak Boleh Negatif, Silahkan Ulang!\n";
        }
    } while (db.HargaBarang < 0);

        do {
            cout << "Masukkan Stok Barang  : ";
            cin >> db.StokBarang;

            if (db.StokBarang < 0){
                cout << "Stok tidak boleh negatif, Silahkan Ulang!\n";
            } 
        } while (db.StokBarang < 0);

        DaftarBarang.push_back(db);
        cout << "Barang berhasil ditambahkan\n";

        KembaliKeMenu();
}

void TampilkanSemuaBarang(const vector<DataBarang>& DaftarBarang) {
    if (DaftarBarang.empty()) {
        cout << "Belum ada data barang.\n";
        KembaliKeMenu();
        return;
    }

    cout << "\n===== DATA BARANG =====\n";
    for (const auto& barang : DaftarBarang) {
        cout << "Kode  : " << barang.KodeBarang  << endl;
        cout << "Nama  : " << barang.NamaBarang  << endl;
        cout << "Harga : " << barang.HargaBarang << endl;
        cout << "Stok  : " << barang.StokBarang  << endl;
        cout << "-----------------------\n";
    }
    
    KembaliKeMenu();
}

void CariBarangTermahal(const vector<DataBarang>& DaftarBarang) {
    if (DaftarBarang.empty()) {
        cout << "Data barang kosong.\n";
        KembaliKeMenu();
        return;
    }

    const DataBarang* BarangTermahal = &DaftarBarang[0];
    for (const auto& b : DaftarBarang) {
        if (b.HargaBarang > BarangTermahal->HargaBarang) {
            BarangTermahal = &b;
        }
    }
    cout << "Barang termahal:\n";
    cout << "Kode  : " << BarangTermahal->KodeBarang  << endl;
    cout << "Nama  : " << BarangTermahal->NamaBarang  << endl;
    cout << "Harga : " << BarangTermahal->HargaBarang << endl;
    cout << "Stok  : " << BarangTermahal->StokBarang  << endl;

    KembaliKeMenu();
}

void HitungTotalNilai(const vector<DataBarang>& DaftarBarang) {
    double total = 0;

    for (const auto& db : DaftarBarang) {
        total += db.HargaBarang * db.StokBarang;
    }
    cout << "Total nilai inventaris : Rp " << total << endl;

    KembaliKeMenu();
}

void CekRestock(const vector<DataBarang>& DaftarBarang) {
    bool ada = false;

    for (const auto& db : DaftarBarang) {
        if (db.StokBarang < 5) {
            cout << "Kode : " << db.KodeBarang << " | Nama : " << db.NamaBarang << " | Stok : " << db.StokBarang << endl;
            ada = true;
        }
    }
    if (!ada) {
        cout << "Tidak ada barang yang perlu direstock\n";
    }

    KembaliKeMenu();
}

void UpdateStok(vector<DataBarang>& DaftarBarang) {
    string KodeCari;

    cout << "Masukkan kode barang : ";
    cin >> KodeCari;

    bool ditemukan = false;
    for (auto& db : DaftarBarang) {
        if (db.KodeBarang == KodeCari) {
            ditemukan = true;

            int perubahan;
            cout << "Stok saat ini : " << db.StokBarang << "\n";
            cout << "Masukkan jumlah stok yang akan ditambah (+) atau dikurangi (-) : ";
            cin  >> perubahan;

            if (db.StokBarang + perubahan < 0) {
                cout << "Stok tidak boleh negatif setelah update\n";
            } else {
                int* ptrStok = &db.StokBarang; 
                *ptrStok += perubahan;
                cout << "Stok berhasil diperbarui.\n";
                cout << "Stok baru : " << db.StokBarang << endl;
            }

            break;
        }
    }
    if (!ditemukan) {
        cout << "Barang tidak ditemukan\n";
    }    
    
    KembaliKeMenu();
}

int main() {
   vector<DataBarang> DaftarBarang;

    int pilihan;
    do {
        Menu();
        cout << "\nPilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                TambahBarang(DaftarBarang);
                break;
            case 2:
                TampilkanSemuaBarang(DaftarBarang);
                break;
            case 3:
                CariBarangTermahal(DaftarBarang);
                break;
            case 4:
                HitungTotalNilai(DaftarBarang);
                break;
            case 5:
                CekRestock(DaftarBarang);
                break;
            case 6:
                UpdateStok(DaftarBarang);
                break;
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
                KembaliKeMenu();
        }
    } while (pilihan != 7);

    return 0;
}