# 📘 Campus Life Assistant

Aplikasi berbasis C++ untuk membantu mahasiswa Universitas Gadjah Mada (UGM) mengelola kehidupan kampus dengan sistem manajemen personal yang terintegrasi.

---

Berikut Website Deploy Awal (Wireframe awal) Yang Nantinya Bisa Dikembangkan dengan integrasi C++ :
https://campus-life-assistant-webprototype-git-main-gauzamf22s-projects.vercel.app/


## 📌 Deskripsi Proyek

Campus Life Assistant adalah aplikasi desktop yang dirancang khusus untuk meningkatkan produktivitas akademik dan aktivitas harian mahasiswa melalui berbagai fitur manajemen terintegrasi.

---

## 👥 Tim Pengembang

1.	Anisa Karlina Febriyanti (Kimia/566999)
2.	Farrel Fata Varian Nugraha(Ilmu Komputer/564457)
3.	Muhammad Daffa Abhinaya (Fisika/562026)
4.	Muhammad Gauza Faliha (Ilmu Komputer/555851) 
5.	Riyan Ramadhan Elfatih (Elins/562137) 
6.	Rizky Auliawati (Kimia/559954) 
7.	Sandy Adiyatma Pramana (Ilmu Komputer/567854)

## Tugas Tiap Pengembang 

1.	Anisa Karlina Febriyanti (Kimia/566999) ~ Testing dan Laporan 
2.	Farrel Fata Varian Nugraha(Ilmu Komputer/564457) ~ Programmer (Modular Sistem) 
3.	Muhammad Daffa Abhinaya (Fisika/562026) ~ Testing dan Laporan
4.	Muhammad Gauza Faliha (Ilmu Komputer/555851) ~ Lead of team (Programmer (main) )
5.	Riyan Ramadhan Elfatih (Elins/562137) ~ Algoritma dan Flowchart
6.	Rizky Auliawati (Kimia/559954) ~ Testing dan Laporan
7.	Sandy Adiyatma Pramana (Ilmu Komputer/567854) ~ Programmer (Modular Sistem)
---

## 🎯 Fitur Utama

### 1. Academic Tools
- **Notes Manager** — CRUD catatan kuliah dengan sistem ID otomatis
- **Study Planner** — Perencanaan dan tracking sesi belajar

### 2. Student Life Tools
- **Expense Tracker** — Pencatatan pengeluaran harian dengan visualisasi
- **Personal Task Organizer** — Task management dengan prioritas & deadline

### 3. Reports & Insights
- Laporan mingguan otomatis
- Productivity index calculation
- Analisis pengeluaran & perkembangan akademik

### 4. Settings
- Kustomisasi nama pengguna
- Pengaturan mata uang
- Backup dan restore data

---

## 📚 Library yang Digunakan

### Library Standar C++

| Library | Fungsi | Penggunaan |
|---------|--------|------------|
| `<iostream>` | Input/Output | Menu & input pengguna |
| `<vector>` | Dynamic container | Penyimpanan koleksi data |
| `<string>` | Manipulasi teks | Judul, subjek, isi catatan |
| `<fstream>` | File I/O | Persistensi data |
| `<algorithm>` | Sorting & searching | Sorting tugas & find_if |
| `<iomanip>` | Formatting | Tabel & bar chart |
| `<sstream>` | Parsing data | Membaca CSV |
| `<map>` | Key-value storage | Kategori pengeluaran |
| `<thread>` | Multithreading | Typing animation |
| `<chrono>` | Time utilities | Delay & timer |

### Library Windows-Specific

| Library | Fungsi | Penggunaan |
|---------|--------|------------|
| `<conio.h>` | Console I/O | `_getch()` |
| `<windows.h>` | Windows API | Warna, posisi kursor, beep |

---

## 🔧 Fungsi Utility

### Manipulasi Console
- `gotoxy(x,y)` — Memindahkan kursor console
- `hideCursor()` — Menyembunyikan cursor
- `setColor(color)` — Mengatur warna teks
- `clearScreen()` — Membersihkan layar

### Animasi & Efek Visual
- `delayPrint()` — Efek mengetik
- `slideUp()` — ASCII art bergerak
- `printColoredASCII()` — ASCII art berwarna
- `welcomeScreen()` — Layar sambutan
- `goodbyeScreen()` — Layar penutup

### Helper
- `makeDecision(options)` — Menu dinamis

---

## 🗂️ Struktur Data

### 1. Catatan
```cpp
struct Catatan {
    int id;
    string subjek;
    string isi;
    string tanggal;
};
```

### 2. Sesi Belajar
```cpp
struct SesiBelajar {
    string subjek;
    string tanggal;
    double jam;
    bool selesai;
};
```

### 3. Pengeluaran
```cpp
struct Pengeluaran {
    string tanggal;
    string kategori;
    double jumlah;
};
```

### 4. Tugas
```cpp
struct Tugas {
    int id;
    string judul;
    string tenggat;
    bool selesai;
};
```


## 🏗️ Arsitektur Kelas

### 1. PengelolaCatatan
- CRUD catatan
- Auto-increment ID
- **Penyimpanan:** `notes.txt`

### 2. PerencanaBelajar
- Menambah & menandai sesi belajar
- Hitung produktivitas
- **Penyimpanan:** `study_sessions.txt`

### 3. PelacakPengeluaran
- Pencatatan pengeluaran
- ASCII bar chart
- Grouping kategori dengan `map`
- **Penyimpanan:** `expenses.txt`

### 4. PengorganisirTugas
- CRUD tugas
- Smart sorting by deadline & status
- **Penyimpanan:** `tasks.txt`

### 5. Laporan
- Generate weekly report
- Hitung productivity index

### 6. Pengaturan
- Atur nama & mata uang
- Backup data

---

## ✅ Kelebihan Aplikasi

### 1. User Experience
- Animasi ASCII art berwarna
- Countdown opening & closing
- Interface bersih & konsisten

### 2. Fitur Teknis
- Persistent storage
- Auto-save
- Auto-increment ID
- ASCII visualizations

### 3. Fungsionalitas
- CRUD Notes & Tasks
- Productivity index
- Weekly reports
- Expense categorization

### 4. Code Quality
- OOP dengan class terpisah
- Encapsulation
- Modular & mudah dikembangkan

### 5. Praktikal
- Dirancang untuk mahasiswa
- Tanpa internet
- Bisa dibuat cross-platform

---

## ⭐ Evaluasi & Rencana Pengembangan

### 1. Dependency Platform
**Saat ini:** Windows-only  (Belum bisa untuk Mac)
**Rencana:** Mendukung library cross-platform

### 2. Pengelolaan Data
**Saat ini:** Penyimpanan sederhana  
**Rencana:** Format data lebih aman & stabil

### 3. Validasi Input
**Saat ini:** Deteksi error terbatas  
**Rencana:** Modul validasi lebih robust

### 4. Antarmuka Pengguna
**Saat ini:** Navigasi berbasis angka  
**Rencana:** Navigasi interaktif + search/filter

### 5. Fitur Aplikasi
**Saat ini:** Belum ada reminder & kalender  
**Rencana:** Notifikasi, export data, calendar view

### 6. Settings
**Saat ini:** Konfigurasi belum persistent  
**Rencana:** Sistem config permanen

### 7. Aspek Kode
**Saat ini:** Beberapa bagian bisa dioptimalkan  
**Rencana:** Refactoring + unit testing

### 8. Skalabilitas
**Saat ini:** Bisa melambat saat data besar  
**Rencana:** Struktur penyimpanan lebih efisien

---

## 📂 Struktur File

```
Campus-Life-Assistant/
│
├── main.cpp
├── notes.txt
├── study_sessions.txt
├── expenses.txt
├── tasks.txt
├── backup.csv
└── README.md
```

---

## 🚀 Cara Instalasi & Menjalankan

### Requirements
- Windows OS
- MinGW-g++ / Visual Studio
- C++11 atau lebih baru

### Compile
```bash
g++ main.cpp -o CampusLifeAssistant.exe -std=c++11
```

### Run
```bash
./CampusLifeAssistant.exe
```

---

## 🔮 Ide Pengembangan di Masa yang akan datang atau seiring berjalannya waktu

- [ ] GUI dengan Qt/wxWidgets
- [ ] Cloud sync (Firebase/Google Drive)
- [ ] Mobile companion app
- [ ] AI-based analytics
- [ ] Share notes with classmates
- [ ] Gamification (achievement system)
- [ ] Integrasi SIMASTER UGM (jika API tersedia)

---

## 📝 Lisensi

Project ini dibuat untuk keperluan akademik Universitas Gadjah Mada sebagai Project PRG.

---

## 🎓 Terima Kasih!

Terima kasih telah menggunakan Campus Life Assistant. Semoga aplikasi ini dapat membantu meningkatkan produktivitas akademik khususnya di UGM!
```
