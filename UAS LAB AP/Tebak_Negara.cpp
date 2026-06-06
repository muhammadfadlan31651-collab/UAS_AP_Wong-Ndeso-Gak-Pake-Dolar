#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <cctype>

using namespace std;

// Fungsi bantuan untuk mengubah string menjadi huruf kecil (lowercase)
string to_lowercase(const string& str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c){ return tolower(c); });
    return lower_str;
}

// Fungsi untuk membaca data negara dari file CSV
vector<string> load_countries(const string& filename) {
    vector<string> countries;
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        // Melewati baris pertama (header)
        getline(file, line);
        
        // Membaca baris demi baris
        while (getline(file, line)) {
            // Menghapus karakter carriage return (\r) jika ada
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }
            if (!line.empty()) {
                countries.push_back(line);
            }
        }
        file.close();
    } else {
        cerr << "Error: File '" << filename << "' tidak ditemukan.\n";
    }
    return countries;
}

// Fungsi untuk menyembunyikan huruf secara acak dari nama negara
string hide_letters(const string& country) {
    string clue = to_lowercase(country);
    vector<int> valid_indices;

    // Mendapatkan indeks yang merupakan huruf (mengabaikan spasi jika ada)
    for (size_t i = 0; i < clue.length(); ++i) {
        if (clue[i] != ' ') {
            valid_indices.push_back(i);
        }
    }

    // Menentukan jumlah huruf yang akan disembunyikan
    int num_to_hide = valid_indices.size() / 2;
    if (num_to_hide == 0 && !valid_indices.empty()) {
        num_to_hide = 1;
    }

    // Mengacak indeks menggunakan generator modern C++
    random_device rd;
    mt19937 g(rd());
    shuffle(valid_indices.begin(), valid_indices.end(), g);

    // Mengubah huruf pada indeks yang terpilih menjadi garis bawah
    for (int i = 0; i < num_to_hide; ++i) {
        clue[valid_indices[i]] = '_';
    }

    return clue;
}

int main() {
    string filename = "50_popular_countries.csv";
    vector<string> countries = load_countries(filename);

    if (countries.empty()) {
        cout << "Gagal memulai game karena data negara kosong.\n";
        return 1;
    }

    int score = 0;
    string play_again = "y";
    
    // Inisialisasi generator angka acak untuk memilih negara
    random_device rd;
    mt19937 gen(rd());

    // Loop utama permainan
    while (to_lowercase(play_again) == "y") {
        uniform_int_distribution<> dis(0, countries.size() - 1);
        string chosen_country = countries[dis(gen)];
        string clue = hide_letters(chosen_country);

        cout << "\nTebak negara: " << clue << "\n";
        cout << "Negara apakah yang dimaksud? ";
        
        string answer;
        getline(cin, answer);
        
        // Pengecekan jawaban (case-insensitive)
        if (to_lowercase(answer) == to_lowercase(chosen_country)) {
            cout << "Selamat! Anda benar.\n";
            score++;
        } else {
            cout << "Maaf, jawaban Anda salah. Coba lagi.\n";
        }
        
        cout << "Skor Anda: " << score << "\n";
        
        // Menanyakan apakah ingin lanjut bermain
        cout << "Ingin bermain lagi? (y/n): ";
        getline(cin, play_again);
    }

    cout << "\nGame Selesai :D\n";
    return 0;
}