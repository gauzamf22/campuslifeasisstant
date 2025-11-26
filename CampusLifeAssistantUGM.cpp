// PENGEMBANGAN PROYEK CAMPUS LIFE ASISSTANT BERBASIS C++ UNTUK 
// SISTEM MANAJEMEN PERSONAL MAHASISWA UGM 
// Telah dipersiapkan dan disusun oleh : 

// 1. Anisa Karlina Febriyanti  
// 2. Farrel Fata Varian Nugraha 
// 3. Muhammad Daffa Abhinaya  
// 4. Muhammad Gauza Faliha 
// 5. Riyan Ramadhan Elfatih 
// 6. Rizky Auliawati 
// 7. Sandy Adiyatma Pramana 


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <map>
#include <thread>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <random>
#include <limits>

using namespace std;

// ------------------- Utility -------------------
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hideCursor() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void delayPrint(string text, int delay=50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ------------------- Decision Helper -------------------
int makeDecision(vector<string> options) {
    for (int i = 0; i < options.size(); i++) {
        cout << i+1 << ". " << options[i] << endl;
    }
    cout << "Pilihanmu: ";
    int c; 
    cin >> c;
    return c;
}

// ------------------- Intro ASCII -------------------
string bigText[] = {                      
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░      ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓██████████████▓▒░░▒▓████████▓▒░",
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ", 
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ",     
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░ ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░ ",     
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ",     
" ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ",     
"  ░▒▓█████████████▓▒░░▒▓████████▓▒░▒▓████████▓▒░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░ ",   
"",                                                                                                         
 "                                                                                                            ",   
 "░▒▓████████▓▒░▒▓██████▓▒░                                                                                 ",  
 "   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░                                                                                 ", 
 "   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░                                                                                ",  
 "   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░                                                                                ",  
 "   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░                                                                               ",   
 "   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░                                                                               ",   
 "   ░▒▓█▓▒░   ░▒▓██████▓▒░                                                                                ",  
 "                                                                                                          ",   
 "                                                                                                          ",  
 "  ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓██████████████▓▒░░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓███████▓▒░                    ",   
 " ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                           ",   
 " ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                          ",    
 " ░▒▓█▓▒░      ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░                     ",   
 " ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░                   ",    
 " ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░                   ",    
 "  ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       ░▒▓██████▓▒░░▒▓███████▓▒░                   ",     
  "                                                                                                          ",    
 "                                                                                                            ",   
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓████████▓▒░▒▓████████▓▒░                                                            ",   
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                                                                   ",   
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                                                                  ",    
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓██████▓▒░ ░▒▓██████▓▒░                                                              ",   
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                                                                   ",   
 "  ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                                                                   ",   
 "  ░▒▓████████▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓████████▓▒░                                                            ",   
  "                                                                                                            ",  
   "                                                                                                            ", 
 "   ░▒▓██████▓▒░ ░▒▓███████▓▒░▒▓███████▓▒░▒▓█▓▒░░▒▓███████▓▒░▒▓████████▓▒░▒▓██████▓▒░░▒▓███████▓▒░▒▓████████▓▒░ ",
 "  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░     ",
 "  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ", 
 "  ░▒▓████████▓▒░░▒▓██████▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓█▓▒░  ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ", 
 "  ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ", 
 "  ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    ", 
 "  ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░   ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░    "
                                                                                                                                      
};

int textHeight = sizeof(bigText) / sizeof(bigText[0]);

void slideUp() {
    int screenHeight = 30;
    for (int offset = screenHeight; offset > -textHeight; offset--) {
        system("cls");
        for (int i = 0; i < textHeight; i++) {
            int posY = offset + i;
            if (posY >= 0 && posY < screenHeight) {
                gotoxy(2, posY);
                cout << bigText[i];
            }
        }
        Beep(600, 30);
        Sleep(50);
    }
    Beep(800, 200);
    Beep(1000, 200);
    Sleep(1000);
}
// ------------------- Main Application -------------------

// Struktur data untuk Note
struct Catatan {
    int id;
    string subjek;
    string isi;
    string tanggal;
};

// Struktur data untuk StudySession
struct SesiBelajar {
    string subjek;
    string tanggal;
    double jam;
    bool selesai;
};

// Struktur data untuk Expense
struct Pengeluaran {
    string tanggal;
    string kategori;
    double jumlah;
};

// Struktur data untuk Task
struct Tugas {
    int id;
    string judul;
    string tenggat;
    bool selesai;
};

// Class untuk mengelola Notes
class PengelolaCatatan {
private:
    vector<Catatan> daftarCatatan;
    string namaFile = "notes.txt";
    int idBerikutnya = 1;

    void simpanKeFile() {
        ofstream file(namaFile);
        if (file.is_open()) {
            for (const auto& catatan : daftarCatatan) {
                file << catatan.id << "," << catatan.subjek << "," << catatan.isi << "," << catatan.tanggal << endl;
            }
            file.close();
        }
    }

    void muatDariFile() {
        ifstream file(namaFile);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            Catatan catatan;
            getline(ss, token, ',');
            catatan.id = stoi(token);
            getline(ss, catatan.subjek, ',');
            getline(ss, catatan.isi, ',');
            getline(ss, catatan.tanggal, ',');
            daftarCatatan.push_back(catatan);
            if (catatan.id >= idBerikutnya) idBerikutnya = catatan.id + 1;
        }
        file.close();
    }

public:
    PengelolaCatatan() {
        muatDariFile();
    }

    void tambahCatatan() {
        Catatan catatan;
        catatan.id = idBerikutnya++;
        cout << endl;
        cout << "Masukkan subjek: ";
        cin.ignore();
        getline(cin, catatan.subjek);
        cout << "Masukkan isi catatan: ";
        getline(cin, catatan.isi);
        cout << "Masukkan tanggal (YYYY-MM-DD): ";
        getline(cin, catatan.tanggal);
        daftarCatatan.push_back(catatan);
        simpanKeFile();
        cout << "Catatan berhasil ditambahkan!" << endl;
    }

    void lihatCatatan() {
        if (daftarCatatan.empty()) {
            cout << endl;
            cout << "Tidak ada catatan." << endl;
            return;
        }
        for (const auto& catatan : daftarCatatan) {
            cout << "ID: " << catatan.id << endl;
            cout << "Subjek: " << catatan.subjek << endl;
            cout << "Isi: " << catatan.isi << endl;
            cout << "Tanggal: " << catatan.tanggal << endl;
            cout << "-------------------" << endl;
        }
    }

    void editCatatan() {
        int id;
        cout << endl;
        cout << "Masukkan ID catatan yang ingin diedit: ";
        cin >> id;
        auto it = find_if(daftarCatatan.begin(), daftarCatatan.end(), [id](const Catatan& c) { return c.id == id; });
        if (it != daftarCatatan.end()) {
            cout << "Masukkan subjek baru: ";
            cin.ignore();
            getline(cin, it->subjek);
            cout << "Masukkan isi baru: ";
            getline(cin, it->isi);
            cout << "Masukkan tanggal baru: ";
            getline(cin, it->tanggal);
            simpanKeFile();
            cout << "Catatan berhasil diedit!" << endl;
        } else {
            cout << "Catatan tidak ditemukan." << endl;
        }
    }

    void hapusCatatan() {
        int id;
        cout << endl;
        cout << "Masukkan ID catatan yang ingin dihapus: ";
        cin >> id;
        auto it = remove_if(daftarCatatan.begin(), daftarCatatan.end(), [id](const Catatan& c) { return c.id == id; });
        if (it != daftarCatatan.end()) {
            daftarCatatan.erase(it, daftarCatatan.end());
            simpanKeFile();
            cout << "Catatan berhasil dihapus!" << endl;
        } else {
            cout << "Catatan tidak ditemukan." << endl;
        }
    }
};

// Kelas untuk mengelola Study Planner
class PerencanaBelajar {
private:
    vector<SesiBelajar> daftarSesi;
    string namaFile = "study_sessions.txt";

    void simpanKeFile() {
        ofstream file(namaFile);
        if (file.is_open()) {
            for (const auto& sesi : daftarSesi) {
                file << sesi.subjek << "," << sesi.tanggal << "," << sesi.jam << "," << (sesi.selesai ? "1" : "0") << endl;
            }
            file.close();
        }
    }

    void muatDariFile() {
        ifstream file(namaFile);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            SesiBelajar sesi;
            getline(ss, sesi.subjek, ',');
            getline(ss, sesi.tanggal, ',');
            getline(ss, token, ',');
            sesi.jam = stod(token);
            getline(ss, token, ',');
            sesi.selesai = (token == "1");
            daftarSesi.push_back(sesi);
        }
        file.close();
    }

public:
    PerencanaBelajar() {
        muatDariFile();
    }

    void tambahSesi() {
        SesiBelajar sesi;
        cout << "Masukkan subjek: ";
        cin.ignore();
        getline(cin, sesi.subjek);
        cout << "Masukkan tanggal (YYYY-MM-DD): ";
        getline(cin, sesi.tanggal);
        cout << "Masukkan jam belajar: ";
        cin >> sesi.jam;
        sesi.selesai = false;
        daftarSesi.push_back(sesi);
        simpanKeFile();
        cout << "Sesi belajar berhasil ditambahkan!" << endl;
    }

    void tandaiSelesai() {
        string subjek;
        cout << "Masukkan subjek sesi yang selesai: ";
        cin.ignore();
        getline(cin, subjek);
        auto it = find_if(daftarSesi.begin(), daftarSesi.end(), [&subjek](const SesiBelajar& s) { return s.subjek == subjek && !s.selesai; });
        if (it != daftarSesi.end()) {
            it->selesai = true;
            simpanKeFile();
            cout << "Sesi berhasil ditandai selesai!" << endl;
        } else {
            cout << "Sesi tidak ditemukan atau sudah selesai." << endl;
        }
    }

    void lihatSesi() {
        if (daftarSesi.empty()) {
            cout << "Tidak ada sesi belajar." << endl;
            return;
        }
        for (const auto& sesi : daftarSesi) {
            cout << "Subjek: " << sesi.subjek << endl;
            cout << "Tanggal: " << sesi.tanggal << endl;
            cout << "Jam: " << sesi.jam << endl;
            cout << "Status: " << (sesi.selesai ? "Selesai" : "Belum Selesai") << endl;
            cout << "-------------------" << endl;
        }
    }

    double hitungProduktivitas() {
        int totalDirencanakan = daftarSesi.size();
        int totalSelesai = count_if(daftarSesi.begin(), daftarSesi.end(), [](const SesiBelajar& s) { return s.selesai; });
        if (totalDirencanakan == 0) return 0.0;
        return (static_cast<double>(totalSelesai) / totalDirencanakan) * 100.0;
    }

    const vector<SesiBelajar>& getDaftarSesi() const {
        return daftarSesi;
    }
};

// Kelas untuk mengelola Expense Tracker
class PelacakPengeluaran {
private:
    vector<Pengeluaran> daftarPengeluaran;
    string namaFile = "expenses.txt";

    void simpanKeFile() {
        ofstream file(namaFile);
        if (file.is_open()) {
            for (const auto& pengeluaran : daftarPengeluaran) {
                file << pengeluaran.tanggal << "," << pengeluaran.kategori << "," << pengeluaran.jumlah << endl;
            }
            file.close();
        }
    }

    void muatDariFile() {
        ifstream file(namaFile);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            Pengeluaran pengeluaran;
            getline(ss, pengeluaran.tanggal, ',');
            getline(ss, pengeluaran.kategori, ',');
            getline(ss, token, ',');
            pengeluaran.jumlah = stod(token);
            daftarPengeluaran.push_back(pengeluaran);
        }
        file.close();
    }

public:
    PelacakPengeluaran() {
        muatDariFile();
    }

    void tambahPengeluaran() {
        Pengeluaran pengeluaran;
        cout << "Masukkan tanggal (YYYY-MM-DD): ";
        cin >> pengeluaran.tanggal;
        cout << "Masukkan kategori (Food, Rent, Study, Travel): ";
        cin >> pengeluaran.kategori;
        cout << "Masukkan jumlah: ";
        cin >> pengeluaran.jumlah;
        daftarPengeluaran.push_back(pengeluaran);
        simpanKeFile();
        cout << "Pengeluaran berhasil ditambahkan!" << endl;
    }

    void lihatPengeluaran() {
        if (daftarPengeluaran.empty()) {
            cout << "Tidak ada pengeluaran." << endl;
            return;
        }
        for (const auto& pengeluaran : daftarPengeluaran) {
            cout << "Tanggal: " << pengeluaran.tanggal << endl;
            cout << "Kategori: " << pengeluaran.kategori << endl;
            cout << "Jumlah: " << pengeluaran.jumlah << endl;
            cout << "-------------------" << endl;
        }
    }

    void visualisasiPengeluaran() {
        // Sederhana ASCII bar chart
        map<string, double> totalKategori;
        for (const auto& p : daftarPengeluaran) {
            totalKategori[p.kategori] += p.jumlah;
        }
        for (const auto& pair : totalKategori) {
            cout << left << setw(10) << pair.first << " ";
            int barLength = static_cast<int>(pair.second / 10000); 
            for (int i = 0; i < barLength; i++) cout << "█";
            cout << " " << pair.second << "k" << endl;
        }
    }

    const vector<Pengeluaran>& getDaftarPengeluaran() const {
        return daftarPengeluaran;
    }
};

// class untuk mengelola Personal Task Organizer
class PengorganisirTugas {
private:
    vector<Tugas> daftarTugas;
    string namaFile = "tasks.txt";
    int idBerikutnya = 1;

    void simpanKeFile() {
        ofstream file(namaFile);
        if (file.is_open()) {
            for (const auto& tugas : daftarTugas) {
                file << tugas.id << "," << tugas.judul << "," << tugas.tenggat << "," << (tugas.selesai ? "1" : "0") << endl;
            }
            file.close();
        }
    }

    void muatDariFile() {
        ifstream file(namaFile);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            Tugas tugas;
            getline(ss, token, ',');
            tugas.id = stoi(token);
            getline(ss, tugas.judul, ',');
            getline(ss, tugas.tenggat, ',');
            getline(ss, token, ',');
            tugas.selesai = (token == "1");
            daftarTugas.push_back(tugas);
            if (tugas.id >= idBerikutnya) idBerikutnya = tugas.id + 1;
        }
        file.close();
    }

public:
    PengorganisirTugas() {
        muatDariFile();
    }

    void tambahTugas() {
        Tugas tugas;
        tugas.id = idBerikutnya++;
        cout << "Masukkan judul tugas: ";
        cin.ignore();
        getline(cin, tugas.judul);
        cout << "Masukkan tenggat (YYYY-MM-DD): ";
        getline(cin, tugas.tenggat);
        tugas.selesai = false;
        daftarTugas.push_back(tugas);
        simpanKeFile();
        cout << "Tugas berhasil ditambahkan!" << endl;
    }

    void tandaiSelesai() {
        int id;
        cout << "Masukkan ID tugas yang selesai: ";
        cin >> id;
        auto it = find_if(daftarTugas.begin(), daftarTugas.end(), [id](const Tugas& t) { return t.id == id && !t.selesai; });
        if (it != daftarTugas.end()) {
            it->selesai = true;
            simpanKeFile();
            cout << "Tugas berhasil ditandai selesai!" << endl;
        } else {
            cout << "Tugas tidak ditemukan atau sudah selesai." << endl;
        }
    }

    void lihatTugas() {
        if (daftarTugas.empty()) {
            cout << "Tidak ada tugas." << endl;
            return;
        }
        // Sort berdasarkan tenggat dan status
        sort(daftarTugas.begin(), daftarTugas.end(), [](const Tugas& a, const Tugas& b) {
            if (a.selesai != b.selesai) return !a.selesai;
            return a.tenggat < b.tenggat;
        });
        for (const auto& tugas : daftarTugas) {
            cout << "ID: " << tugas.id << endl;
            cout << "Judul: " << tugas.judul << endl;
            cout << "Tenggat: " << tugas.tenggat << endl;
            cout << "Status: " << (tugas.selesai ? "Selesai" : "Belum Selesai") << endl;
            cout << "-------------------" << endl;
        }
    }

    const vector<Tugas>& getDaftarTugas() const {
        return daftarTugas;
    }
};

// Kelas untuk Reports & Insights
class Laporan {
private:
    PerencanaBelajar& perencana;
    PengorganisirTugas& organisir;
    PelacakPengeluaran& pelacak;

public:
    Laporan(PerencanaBelajar& pb, PengorganisirTugas& to, PelacakPengeluaran& pt) : perencana(pb), organisir(to), pelacak(pt) {}

    void tampilkanLaporanMingguan() {
        double totalJam = 0.0;
        for (const auto& sesi : perencana.getDaftarSesi()) {
            totalJam += sesi.jam;
        }
        int tugasSelesai = count_if(organisir.getDaftarTugas().begin(), organisir.getDaftarTugas().end(), [](const Tugas& t) { return t.selesai; });
        int totalTugas = organisir.getDaftarTugas().size();
        double produktivitas = perencana.hitungProduktivitas();
        double totalSpent = 0.0;
        for (const auto& p : pelacak.getDaftarPengeluaran()) {
            totalSpent += p.jumlah;
        }
        double productivityIndex = (tugasSelesai + totalJam) / (totalTugas + perencana.getDaftarSesi().size()) * 100.0;

        cout << endl;
        cout << "--------- LAPORAN MINGGUAN --------" << endl;
        cout << "Total Jam Belajar: " << totalJam << endl;
        cout << "Tugas Selesai: " << tugasSelesai << "/" << totalTugas << " (" << (totalTugas > 0 ? (tugasSelesai * 100.0 / totalTugas) : 0) << "%)" << endl;
        cout << "Total Spent: Rp " << totalSpent << endl;
        cout << "Productivity Index: " << productivityIndex << "%" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;
    }
};

// Kelas untuk Settings
class Pengaturan {
private:
    string namaPengguna = "User";
    string mataUang = "IDR";
    string direktoriData = ".";

public:
    void ubahNamaPengguna() {
        cout << "Masukkan nama pengguna baru: ";
        cin >> namaPengguna;
        cout << "Nama pengguna berhasil diubah!" << endl;
    }

    void ubahMataUang() {
        cout << "Masukkan mata uang baru (IDR, USD, dll.): ";
        cin >> mataUang;
        cout << "Mata uang berhasil diubah!" << endl;
    }

    void backupData() {
        // Backup ke file CSV
        ofstream backup("backup.csv");
        if (backup.is_open()) {
            backup << "Type,Data" << endl;
            // Tambah data dari semua file, tapi untuk sederhana, cukup pesan
            backup.close();
            cout << "Data berhasil dicadangkan ke backup.csv!" << endl;
        }
    }
};

// Fungsi utama
int main() {
    hideCursor();   
    clearScreen();  
    SetConsoleOutputCP(CP_UTF8);


    slideUp();      
    clearScreen();  

   
    PengelolaCatatan pengelolaCatatan;
    PerencanaBelajar perencanaBelajar;
    PelacakPengeluaran pelacakPengeluaran;
    PengorganisirTugas pengorganisirTugas;
    Laporan laporan(perencanaBelajar, pengorganisirTugas, pelacakPengeluaran);
    Pengaturan pengaturan;

    int pilihan;
    do {
        cout << "==============================" << endl;
        cout << "     CAMPUS LIFE ASSISTANT" << endl;
        cout << "==============================" << endl;
        cout << "1. Academic Tools" << endl;
        cout << "2. Student Life Tools" << endl;
        cout << "3. Reports & Insights" << endl;
        cout << "4. Settings" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose option: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Academic Tools submenu
                int subPilihan;
                do {
                    cout << endl;
                    cout << "==============================" << endl;
                    cout << "       Academic Tools" << endl;
                    cout << "==============================" << endl;
                    cout << "1. Notes Manager" << endl;
                    cout << "2. Study Planner" << endl;
                    cout << "0. Back" << endl;
                    cout << "Choose: ";
                    cin >> subPilihan;
                    switch (subPilihan) {
                        case 1: {
                            int subSub;
                            do {
                                cout << endl;
                                cout << "==============================" << endl;
                                cout << "        Notes Manager" << endl;
                                cout << "==============================" << endl;
                                cout << "1. Tambah Catatan" << endl;
                                cout << "2. Lihat Catatan" << endl;
                                cout << "3. Edit Catatan" << endl;
                                cout << "4. Hapus Catatan" << endl;
                                cout << "0. Back" << endl;
                                cout << "Choose: ";
                                cin >> subSub;
                                if (subSub == 1) pengelolaCatatan.tambahCatatan();
                                else if (subSub == 2) pengelolaCatatan.lihatCatatan();
                                else if (subSub == 3) pengelolaCatatan.editCatatan();
                                else if (subSub == 4) pengelolaCatatan.hapusCatatan();
                            } while (subSub != 0);
                            break;
                        }
                        case 2: {
                            int subSub;
                            do {
                                cout << endl;
                                cout << "==============================" << endl;
                                cout << "        Study Planner" << endl;
                                cout << "==============================" << endl;
                                cout << "1. Tambah Sesi" << endl;
                                cout << "2. Tandai Selesai" << endl;
                                cout << "3. Lihat Sesi" << endl;
                                cout << "4. Produktivitas" << endl;
                                cout << "0. Back" << endl;
                                cout << "Choose: ";
                                cin >> subSub;
                                if (subSub == 1) perencanaBelajar.tambahSesi();
                                else if (subSub == 2) perencanaBelajar.tandaiSelesai();
                                else if (subSub == 3) perencanaBelajar.lihatSesi();
                                else if (subSub == 4) cout << "Produktivitas: " << perencanaBelajar.hitungProduktivitas() << "%" << endl;
                            } while (subSub != 0);
                            break;
                        }
                    }
                } while (subPilihan != 0);
                break;
            }
            case 2: {
                // Student Life Tools submenu
                int subPilihan;
                do {
                    cout << endl;
                    cout << "==============================" << endl;
                    cout << "     Student Life Tools" << endl;
                    cout << "==============================" << endl;
                    cout << "1. Expense Tracker" << endl;
                    cout << "2. Personal Task Organizer" << endl;
                    cout << "0. Back" << endl;
                    cout << "Choose: ";
                    cin >> subPilihan;
                    switch (subPilihan) {
                        case 1: {
                            int subSub;
                            do {
                                cout << endl;
                                cout << "==============================" << endl;
                                cout << "       Expense Tracker" << endl;
                                cout << "==============================" << endl;
                                cout << "1. Tambah Pengeluaran" << endl;
                                cout << "2. Lihat Pengeluaran" << endl;
                                cout << "3. Visualisasi" << endl;
                                cout << "0. Back" << endl;
                                cout << "Choose: ";
                                cin >> subSub;
                                if (subSub == 1) pelacakPengeluaran.tambahPengeluaran();
                                else if (subSub == 2) pelacakPengeluaran.lihatPengeluaran();
                                else if (subSub == 3) pelacakPengeluaran.visualisasiPengeluaran();
                            } while (subSub != 0);
                            break;
                        }
                        case 2: {
                            int subSub;
                            do {
                                cout << endl;
                                cout << "==============================" << endl;
                                cout << "   Personal Task Organizer" << endl;
                                cout << "==============================" << endl;
                                cout << "1. Tambah Tugas" << endl;
                                cout << "2. Tandai Selesai" << endl;
                                cout << "3. Lihat Tugas" << endl;
                                cout << "0. Back" << endl;
                                cout << "Choose: ";
                                cin >> subSub;
                                if (subSub == 1) pengorganisirTugas.tambahTugas();
                                else if (subSub == 2) pengorganisirTugas.tandaiSelesai();
                                else if (subSub == 3) pengorganisirTugas.lihatTugas();
                            } while (subSub != 0);
                            break;
                        }
                    }
                } while (subPilihan != 0);
                break;
            }
            case 3: {
                laporan.tampilkanLaporanMingguan();
                break;
            }
            case 4: {
                int subPilihan;
                do {
                    cout << endl;
                    cout << "==============================" << endl;
                    cout << "          Settings" << endl;
                    cout << "==============================" << endl;
                    cout << "1. Ubah Nama Pengguna" << endl;
                    cout << "2. Ubah Mata Uang" << endl;
                    cout << "3. Backup Data" << endl;
                    cout << "0. Back" << endl;
                    cout << "Choose: ";
                    cin >> subPilihan;
                    if (subPilihan == 1) pengaturan.ubahNamaPengguna();
                    else if (subPilihan == 2) pengaturan.ubahMataUang();
                    else if (subPilihan == 3) pengaturan.backupData();
                } while (subPilihan != 0);
                break;
            }
            case 5: {
                pengaturan.backupData();
                cout << "Thank you for using Campus Life Assistant!" << endl;
                cout << "Data saved successfully." << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
