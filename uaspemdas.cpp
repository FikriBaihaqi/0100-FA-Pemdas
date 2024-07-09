/**
* \mainpage Sistem untuk menghitung nilai akhir
*
* \section intro-sec pengantar
* Selamat datang di dokumentasi UAS Pemdas
*
* \section author-sec Tentang Pembuat
* Codingan ini dikerjakan oleh fikri baihaqi adriano dikarenakan ada UAS
* 
* \section note-sec Catatan 
* Dokumentasi ini menggunakan Doxygen
*/

/**
 * @file uaspemdas.cpp
 * @brief Program untuk menghitung nilai akhir dan menentukan kelulusan mahasiswa untuk mata kuliah tertentu.
 */

#include <iostream>
using namespace std;

/**
 * @class MataKuliah
 * @brief Kelas dasar untuk mata kuliah dengan atribut dan metode dasar.
 */
class MataKuliah
{
private: // isi dengan access modifier yang dibutuhkan
    float presensi;
    float activity;
    float exercise;
    float tugasakhir;
        // tambahkan dengan variabel lain yang dibutuhkan dibawah ini
public:
    /**
     * @brief Konstruktor default untuk kelas MataKuliah.
     */
    MataKuliah()
    {
    presensi = 0.0;
    activity = 0.0;
    exercise = 0.0;
    tugasakhir = 0.0;
    // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini
    }

    virtual void namaMataKuliah() { return; }

    /**
     * @brief Menginput nilai mata kuliah.
     */
    virtual void inputNilai() { return; }

    /**
     * @brief Menghitung nilai akhir mata kuliah Pemrograman.
     */
    virtual float hitungNilaiAkhirPemograman() { 
        return (presensi + activity + exercise + tugasakhir) / 4; 
    }

    /**
     * @brief Mengecek apakah mahasiswa lulus mata kuliah.
     */
    virtual void cekKelulusan() {float nilaiAkhir = hitungNilaiAkhirPemograman();
        if (nilaiAkhir >= 75)
            cout << "Selamat, Anda dinyatakan Lulus \n Nilai Akhir : " << nilaiAkhir << endl;
        else
            cout << "Anda dinyatakan Tidak Lulus" << endl;
            }
    // tambahkan virtual fungsi lain yang dibutuhkan dibawah ini

    /**
     * @brief Menghitung nilai akhir mata kuliah Jaringan.
     */
    virtual float hitungNilaiAkhirJaringan() { 
        return (activity + exercise + tugasakhir) / 3; 
    }

    /**
     * @brief Mengatur nilai presensi.
     * @param p Nilai presensi.
     * @param p Nilai Activity.
     */
    void setPresensi(float nilai)
    {
    this->presensi = nilai;
    }
    float getPresensi()
    {
    return presensi;
    }

    void setActivity(float nilai)
    {
    this->activity = nilai;
    }
    float getActivity()
    {
    return activity;
    }

    void setExercise(float nilai)
    {
    this->exercise = nilai;
    }
    float getExercise()
    {
    return exercise;
    }

    void setTugasAkhir(float nilai)
    {
    this->tugasakhir = nilai;
    }
    float getTugasAkhir()
    {
    return tugasakhir;
    }

    // tambahkan setter dan getter lain yang dibutuhkan dibawah ini
    };

    class Pemrograman : public MataKuliah
    {
        public:

         void inputNilai() {
        cout << "Masukkan Nilai Presensi: ";
        float nilPresensi;
        cin >> nilPresensi;
        setPresensi(nilPresensi);

        cout << "Masukkan Nilai Activity: ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai Exercise: ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);

        cout << "Masukkan Nilai Tugas Akhir: ";
        float nilTA;
        cin >> nilTA;
        setTugasAkhir(nilTA);
    }

    float hitungNilaiAkhirPemograman() override {
        return MataKuliah::hitungNilaiAkhirPemograman();
    }

    void cekKelulusan() override {
        return MataKuliah::cekKelulusan();
    }

    // isi disini untuk mengisi kelas pemrograman
    };
    class Jaringan : public MataKuliah
    {
        public:
         void inputNilai() {

        cout << "Masukkan Nilai Activity: ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai Exercise: ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);

        cout << "Masukkan Nilai Tugas Akhir: ";
        float nilTA;
        cin >> nilTA;
        setTugasAkhir(nilTA);
    }
        /**
         * @brief Menghitung nilai akhir untuk mata kuliah Jaringan.
         */
        float hitungNilaiAkhirJaringan() override {
        return MataKuliah::hitungNilaiAkhirJaringan();
    }

     /**
     * @brief Mengecek apakah mahasiswa lulus mata kuliah Jaringan.
     */
    void cekKelulusan() override {
        return MataKuliah::cekKelulusan();
    }

    // isi disini untuk mengisi kelas jaringan
    };

/**
 * @brief Fungsi utama program.
 */
int main()
{
 char pilih;
 MataKuliah *mataKuliah;
 Pemrograman pemro;
 Jaringan jarin;

do {
    cout << "Pilih mata kuliah \n1: Pemrograman \n2: Jaringan \n3: Keluar" << endl;
    cout << " Pilih: ";
    cin >> pilih;

    switch (pilih) {
        case '1':
            mataKuliah = &pemro;
            mataKuliah->inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '2':
            mataKuliah = &jarin;
            mataKuliah->inputNilai();
            mataKuliah->cekKelulusan();
            break;
        case '3':
            cout << "Keluar" << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
 } while(pilih == 'y' || pilih == 'y');
}
 // isi disini untuk menentukan mata kuliah yang dipilih