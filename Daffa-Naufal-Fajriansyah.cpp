#include <iostream>

using namespace std;

string nama_pegawai;
int nip_pegawai;
int tahun_masuk, lama_kerja, jabatan, status_karyawan, status_pernikahan, jumlah_anak;
int gapok;
int tunjangan, tunjangan_tetap, tunjangan_transport, tunjangan_istri, tunjangan_anak, state_tunjangan;
char state = !'Y';
int total_gaji;

int LamaKerja()
{
    int tahun_sekarang = 2022;
    lama_kerja = tahun_sekarang - tahun_masuk;
    return lama_kerja;
}

int Jabatan()
{
    switch (jabatan)
    {
    case 1:
        cout << "Staff" << endl;
        break;
    case 2:
        cout << "Manager" << endl;
        break;
    case 3:
        cout << "Direktur" << endl;
        break;
    }
    return jabatan;
}

int StatusKaryawan()
{
    switch (status_karyawan)
    {
    case 1:
        cout << "Tetap" << endl;
        break;
    case 2:
        cout << "Honorer" << endl;
        break;
    }
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

    return gapok;
}

int Tunjangan()
{
    if (status_karyawan == 1)
    {

        tunjangan_tetap = 2 * gapok;
        cout << "Tunjangan Tetap: ";
        cout << tunjangan_tetap;
    }

    else if (status_karyawan == 2)
    {
        tunjangan_transport = 25 * 15000;
        cout << "Tunjangan Transport: ";
        cout << tunjangan_transport;
    }

    if (status_pernikahan == 1)
    {
        tunjangan_istri = 250000;
        cout << "\nTunjangan Istri: ";
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
            cout << "\nTunjangan Anak: ";
            cout << tunjangan_anak;
        }

        else
        {
            jumlah_anak = 3;
            tunjangan_anak = (200000 * jumlah_anak);
            cout << "\nTunjangan Anak: ";
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
    cout << "Total Gaji: ";
    cout << total_gaji;

    return total_gaji;
}

int State()
{

    gapok = GajiPokok();

    cin >> state;

    if (state == 'Y')
    {
        cout << "Gaji Pokok: ";
        cout << gapok;
        cout << endl;
        state_tunjangan = StateTunjangan();
        cout << "\n=========================================\n";
        total_gaji = TotalGaji();
    }

    else
    {
        cout << "Thanks :D";
    }

    return state;
}

int main()
{

    cout << "Nama Pegawai: ";
    getline(cin, nama_pegawai);
    cout << endl;

    cout << "NIP: ";
    cin >> nip_pegawai;
    cout << endl;

    cout << "Tahun Masuk: ";
    cin >> tahun_masuk;
    cout << endl;

    lama_kerja = LamaKerja();
    cout << "Lama Kerja: ";
    cout << lama_kerja;
    cout << endl;

    jabatan = Jabatan();
    cout << "\nPilih Jabatan: \n";
    cout << "1. Staff \n2. Manager\n3. Direktur\n";
    cout << "Jabatan: ";
    cin >> jabatan;

    status_karyawan = StatusKaryawan();
    cout << "Pilih Status Karyawan: \n";
    cout << "1. Tetap \n2. Honorer\n";
    cout << "Status Karyawan: ";
    cin >> status_karyawan;
    cout << endl;

    status_pernikahan = StatusPernikahan();
    cout << "Pilih Status Pernikahan: \n";
    cout << "1. Menikah \n2. Belum Menikah\n";
    cout << "Status Pernikahan: ";
    cin >> status_pernikahan;

    jumlah_anak = JumlahAnak();

    cout << "Proses Gaji Karyawan: ";
    cout << nama_pegawai;
    cout << " (Y/T): ";
    state = State();

    cin.get();
    return 0;
}