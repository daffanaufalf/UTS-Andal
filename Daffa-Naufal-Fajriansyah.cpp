#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>

using namespace std;

char daffa[256];            // input nama pegawai
long long naufal;           // input nip pegawai
int fajriansyah;            // input tahun masuk
int d;                      // lama kerja
int a;                      // input jabatan
int f;                      // input status karyawan
int j;                      // input status pernikahan
int r;                      // input jumlah anak
int i;                      // gaji pokok
int an;                     // tunjangan tetap
int sy;                     // tunjangan transport
int ah;                     // tunjangan istri
int tunjangan_anak;         // tunjangan anak
int fajri;                  // untuk menampung return dan kondisi tunjangan
char faj = !'Y';            // menampung pilihan Y saat memilih Y/T
float jri;                  // pph
int syah;                   // total gaji
int daf;                    // gaji bersih
int ffa;                    // input programmer
long long nau = 2212500611; // menampung data nim
long long fal;              // input nim

char InputNamaPegawai()
{
    cout << "Nama Pegawai: ";
    scanf(" %[^\n]s", &daffa);
    cout << endl;
    return daffa[256];
}

int InputNIP()
{
    cout << "NIP: ";
    cin >> naufal;
    cout << endl;

    return naufal;
}

int InputTahunMasuk()
{
    cout << "Tahun Masuk: ";
    cin >> fajriansyah;
    cout << endl;

    return fajriansyah;
}

int LamaKerja()
{
    int tahun_sekarang = 2022;
    d = tahun_sekarang - fajriansyah;

    cout << "Lama Kerja: ";
    cout << d;
    cout << endl;

    cin.get();
    return d;
}

int Jabatan()
{
    switch (a)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }

    cout << "\nPilih Jabatan: \n";
    cout << "1. Staff \n2. Manager\n3. Direktur\n";
    cout << "Jabatan: ";
    cin >> a;

    return a;
}

int StatusKaryawan()
{
    switch (f)
    {
    case 1:
        break;
    case 2:
        break;
    }

    cout << "\nPilih Status Karyawan: \n";
    cout << "1. Tetap \n2. Honorer\n";
    cout << "Status Karyawan: ";
    cin >> f;

    return f;
}

int StatusPernikahan()
{
    switch (j)
    {
    case 1:
        cout << "" << endl;
        break;
    case 2:
        cout << "" << endl;
        break;
    }

    cout << "Pilih Status Pernikahan: \n";
    cout << "1. Menikah \n2. Belum Menikah\n";
    cout << "Status Pernikahan: ";
    cin >> j;

    return j;
}

int JumlahAnak()
{
    if (j == 1)
    {
        cout << "Jumlah Anak: ";
        cin >> r;
    }
    return r;
}

int GajiPokok()
{
    if (a == 3)
    {
        i = 7000000;
    }

    else if (a == 2)
    {
        i = 3500000;
    }

    else if (a == 1)
    {
        i = 1500000;
    }

    else
    {
        i = 1000000;
    }

    cout << "Gaji Pokok: \t\t";
    cout << i;
    cout << endl;

    return i;
}

int Tunjangan()
{
    if (f == 1)
    {

        an = 2 * i;
        cout << "Tunjangan Tetap: \t";
        cout << an;
    }

    else if (f == 2)
    {
        sy = 25 * 15000;
        cout << "Tunjangan Transport: \t";
        cout << sy;
    }

    if (j == 1)
    {
        ah = 250000;
        cout << "\nTunjangan Istri: \t";
        cout << ah;
    }

    return an, sy, ah;
}

int TunjanganAnak()
{
    if (j == 1)
    {

        if (r < 4)
        {
            tunjangan_anak = (200000 * r);
            cout << "\nTunjangan Anak: \t";
            cout << tunjangan_anak;
        }

        else
        {
            r = 3;
            tunjangan_anak = (200000 * r);
            cout << "\nTunjangan Anak: \t";
            cout << tunjangan_anak;
        }
    }
    return tunjangan_anak;
}

int StateTunjangan()
{

    an, sy, ah = Tunjangan();
    tunjangan_anak = TunjanganAnak();

    return fajri;
}

int TotalGaji()
{
    syah = i + (an + sy + ah + tunjangan_anak);
    cout << "\nTotal Gaji: \t\t";
    cout << syah;

    return syah;
}

int PPH()
{
    jri = 0.05 * i;
    cout << "\nPPH: \t\t\t";
    cout << jri;

    return jri;
}

int GajiBersih()
{
    daf = syah - jri;
    cout << "\nGaji Bersih: \t\t";
    cout << daf;

    return daf;
}

int Programmer()
{
    cout << "Programmer: ";
    cout << "\nNIM: \t";
    cin >> fal;

    while (fal == nau)
    {
        cout << "Nama: \t";
        cout << "Daffa Naufal Fajriansyah";
        break;
    }

    return ffa;
}

int State()
{

    cout << "Proses Gaji Karyawan: ";
    cout << daffa;
    cout << " (Y/T): ";
    cin >> faj;

    if (faj == 'Y')
    {
        cout << "-------------------------------------------------------\n";
        i = GajiPokok();
        fajri = StateTunjangan();
        cout << "\n=====================================================";
        syah = TotalGaji();
        jri = PPH();
        daf = GajiBersih();
        cout << "\n=====================================================\n";
        ffa = Programmer();
        cout << "\n=====================================================\n";
        cout << "Apakah Anda Ingin Mengulang menggunakan program ini ? (Y/T): ";
        cin >> faj;
        cout << endl;
    }

    else if (faj == 'T')
    {
        cout << "=====================================================\n";
        ffa = Programmer();
        cout << "\n=====================================================\n";
        cout << "Apakah Anda Ingin Mengulang menggunakan program ini ? (Y/T): ";
        cin >> faj;
    }

    return faj;
}

int main()
{
    do
    {
        daffa[256] = InputNamaPegawai();
        naufal = InputNIP();
        fajriansyah = InputTahunMasuk();
        d = LamaKerja();
        a = Jabatan();
        f = StatusKaryawan();
        j = StatusPernikahan();
        r = JumlahAnak();
        faj = State();
    } while (faj == 'Y' || faj == 'y');

    cin.get();
    return 0;
}