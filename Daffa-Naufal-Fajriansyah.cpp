#include <iostream>
#include <istream>

using namespace std;

string nama_pegawai;
int nip_pegawai;
int tahun_masuk, lama_kerja, jabatan, status_karyawan, status_pernikahan, jumlah_anak;
int gapok;
int tunjangan, tunjangan_tetap, tunjangan_transport, tunjangan_istri, tunjangan_anak, state_tunjangan;
char state = !'Y';
float pph;
int total_gaji, gaji_bersih;
int programmer, ulang;
long long nim = 2212500611;
long long input_nim;

string InputNamaPegawai()
{
    cout << "Nama Pegawai: ";
    cin >> nama_pegawai;
    cout << endl;
    return nama_pegawai;
}

int InputNIP()
{
    cout << "NIP: ";
    cin >> nip_pegawai;
    cout << endl;

    return nip_pegawai;
}

int InputTahunMasuk()
{
    cout << "Tahun Masuk: ";
    cin >> tahun_masuk;
    cout << endl;

    return tahun_masuk;
}

int LamaKerja()
{
    int tahun_sekarang = 2022;
    lama_kerja = tahun_sekarang - tahun_masuk;

    cout << "Lama Kerja: ";
    cout << lama_kerja;
    cout << endl;

    return lama_kerja;
}

int Jabatan()
{
    switch (jabatan)
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
    cin >> jabatan;

    return jabatan;
}

int StatusKaryawan()
{
    switch (status_karyawan)
    {
    case 1:
        break;
    case 2:
        break;
    }

    cout << "\nPilih Status Karyawan: \n";
    cout << "1. Tetap \n2. Honorer\n";
    cout << "Status Karyawan: ";
    cin >> status_karyawan;

    return status_karyawan;
}

int StatusPernikahan()
{
    switch (status_pernikahan)
    {
    case 1:
        cout << "" << endl;
        break;
    case 2:
        cout << "" << endl;
        break;
    }

    cout << "\nPilih Status Pernikahan: \n";
    cout << "1. Menikah \n2. Belum Menikah\n";
    cout << "Status Pernikahan: ";
    cin >> status_pernikahan;

    return status_pernikahan;
}

int JumlahAnak()
{
    if (status_pernikahan == 1)
    {
        cout << "Jumlah Anak: ";
        cin >> jumlah_anak;
    }
    return jumlah_anak;
}

int GajiPokok()
{
    if (jabatan == 3)
    {
        gapok = 7000000;
    }

    else if (jabatan == 2)
    {
        gapok = 3500000;
    }

    else if (jabatan == 1)
    {
        gapok = 1500000;
    }

    else
    {
        gapok = 1000000;
    }

    cout << "Gaji Pokok: \t\t";
    cout << gapok;
    cout << endl;

    return gapok;
}

int Tunjangan()
{
    if (status_karyawan == 1)
    {

        tunjangan_tetap = 2 * gapok;
        cout << "Tunjangan Tetap: \t";
        cout << tunjangan_tetap;
    }

    else if (status_karyawan == 2)
    {
        tunjangan_transport = 25 * 15000;
        cout << "\nTunjangan Transport: \t";
        cout << tunjangan_transport;
    }

    if (status_pernikahan == 1)
    {
        tunjangan_istri = 250000;
        cout << "\nTunjangan Istri: \t";
        cout << tunjangan_istri;
    }

    return tunjangan_tetap, tunjangan_transport, tunjangan_istri;
}

int TunjanganAnak()
{
    if (status_pernikahan == 1)
    {

        if (jumlah_anak < 4)
        {
            tunjangan_anak = (200000 * jumlah_anak);
            cout << "\nTunjangan Anak: \t";
            cout << tunjangan_anak;
        }

        else
        {
            jumlah_anak = 3;
            tunjangan_anak = (200000 * jumlah_anak);
            cout << "\nTunjangan Anak: \t";
            cout << tunjangan_anak;
        }
    }
    return tunjangan_anak;
}

int StateTunjangan()
{

    tunjangan_tetap, tunjangan_transport, tunjangan_istri = Tunjangan();
    tunjangan_anak = TunjanganAnak();

    return state_tunjangan;
}

int TotalGaji()
{
    total_gaji = gapok + (tunjangan_tetap + tunjangan_transport + tunjangan_istri + tunjangan_anak);
    cout << "\nTotal Gaji: \t\t";
    cout << total_gaji;

    return total_gaji;
}

int PPH()
{
    pph = 0.05 * gapok;
    cout << "\nPPH: \t\t\t";
    cout << pph;

    return pph;
}

int GajiBersih()
{
    gaji_bersih = total_gaji - pph;
    cout << "\nGaji Bersih: \t\t";
    cout << gaji_bersih;

    return gaji_bersih;
}

int Programmer()
{
    cout << "Programmer: ";
    cout << "\nNIM: \t";
    cin >> input_nim;

    if (input_nim == nim)
    {
        cout << "Nama: \t";
        cout << "Daffa Naufal Fajriansyah";
    }

    return programmer;
}

int State()
{

    cout << "Proses Gaji Karyawan: ";
    cout << nama_pegawai;
    cout << " (Y/T): ";
    cin >> state;

    if (state == 'Y')
    {
        cout << "-------------------------------------------------------\n";
        gapok = GajiPokok();
        state_tunjangan = StateTunjangan();
        cout << "\n=====================================================";
        total_gaji = TotalGaji();
        pph = PPH();
        gaji_bersih = GajiBersih();
        cout << "\n=====================================================\n";
        programmer = Programmer();
        cout << "\n=====================================================\n";
        cout << "Apakah Anda Ingin Mengulang menggunakan program ini ? (Y/T): ";
        cin >> state;
        cout << endl;
    }

    else if (state == 'T')
    {
        cout << "=====================================================\n";
        programmer = Programmer();
        cout << "\n=====================================================\n";
        cout << "Apakah Anda Ingin Mengulang menggunakan program ini ? (Y/T): ";
        cin >> state;
    }

    return state;
}

int main()
{

    do
    {
        nama_pegawai = InputNamaPegawai();
        nip_pegawai = InputNIP();
        tahun_masuk = InputTahunMasuk();
        lama_kerja = LamaKerja();
        jabatan = Jabatan();
        status_karyawan = StatusKaryawan();
        status_pernikahan = StatusPernikahan();
        jumlah_anak = JumlahAnak();
        state = State();
    } while (state == 'Y' or state == 'y');
    cout << "Selesai";

    cin.get();
    return 0;
}