#include <iostream>
#include <string>
using namespace std;

class KTP
{
private:
    int tanggal, rt, rw, bulan, tahun, i, pilihan, maxHari;
    string nik, nama, tempat, kelamin, alamat, kelurahan, kecamatan, agama, status, pekerjaan, kewarganegaraan, berlaku, provinsi, kabupaten, golonganDarah;

    bool nikValid(string nik)
    {
        if (nik.length() != 16)
            return false;
        while (i < nik.length())
        {
            if (!isdigit(nik[i]))
                return false;
            i++;
        }
        return true;
    }

    void inputNik()
    {
        cout << "NIK (16 digit)\t\t: ";
        cin >> nik;

        if (!nikValid(nik))
        {
            cout << "NIK tidak valid, silakan masukkan kembali." << endl;
            inputNik();
        }
    }

    void inputJenisKelamin()
    {
        cout << "Pilih Jenis Kelamin\t: " << endl;
        cout << "1. Laki-laki" << endl;
        cout << "2. Perempuan" << endl;
        cout << "Pilihan (1/2)\t\t: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1)
            kelamin = "Laki-laki";
        else if (pilihan == 2)
            kelamin = "Perempuan";
        else
        {
            cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
            inputJenisKelamin();
        }
    }

    void inputTanggalLahir()
    {
        cout << "Tahun lahir (4 digit)\t: ";
        cin >> tahun;

        do
        {
            cout << "Bulan lahir (2 digit)\t: ";
            cin >> bulan;
            if (bulan < 1 || bulan > 12)
                cout << "Bulan tidak valid, silakan masukkan kembali." << endl;
        } while (bulan < 1 || bulan > 12);

        if (bulan == 2)
        {
            if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0))
            {
                maxHari = 29;
                cout << "Tahun " << tahun << " adalah tahun kabisat." << endl;
            }
            else
            {
                maxHari = 28;
                cout << "Tahun " << tahun << " bukan tahun kabisat." << endl;
            }
        }
        else
            ((bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) ? maxHari = 30 : maxHari = 31);

        do
        {
            cout << "Tanggal lahir (1-" << maxHari << ")\t: ";
            cin >> tanggal;
            if (tanggal < 1 || tanggal > maxHari)
                cout << "Tanggal tidak valid, silakan masukkan kembali." << endl;
        } while (tanggal < 1 || tanggal > maxHari);
    }

    void inputAgama()
    {
        cout << "Pilih Agama\t\t: " << endl;
        cout << "1. Islam" << endl;
        cout << "2. Kristen" << endl;
        cout << "3. Katolik" << endl;
        cout << "4. Hindu" << endl;
        cout << "5. Buddha" << endl;
        cout << "6. Konghucu" << endl;
        cout << "Pilihan (1/2/3/4/5/6)\t: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            agama = "Islam";
            break;
        case 2:
            agama = "Kristen";
            break;
        case 3:
            agama = "Katolik";
            break;
        case 4:
            agama = "Hindu";
            break;
        case 5:
            agama = "Buddha";
            break;
        case 6:
            agama = "Konghucu";
            break;
        default:
            cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
            inputAgama();
            break;
        }
    }

    void inputStatusPerkawinan()
    {
        cout << "Pilih Status Perkawinan\t: " << endl;
        cout << "1. Belum Kawin" << endl;
        cout << "2. Kawin" << endl;
        cout << "3. Cerai Hidup" << endl;
        cout << "4. Cerai Mati" << endl;
        cout << "Pilihan (1/2/3/4)\t: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            status = "Belum Kawin";
            break;
        case 2:
            status = "Kawin";
            break;
        case 3:
            status = "Cerai Hidup";
            break;
        case 4:
            status = "Cerai Mati";
            break;
        default:
            cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
            inputStatusPerkawinan();
            break;
        }
    }

    void inputKewarganegaraan()
    {
        int pilihan;
        cout << "Pilih Kewarganegaraan\t: " << endl;
        cout << "1. WNI (Warga Negara Indonesia)" << endl;
        cout << "2. WNA (Warga Negara Asing)" << endl;
        cout << "Pilihan (1/2)\t\t: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1)
            kewarganegaraan = "WNI";
        else if (pilihan == 2)
            kewarganegaraan = "WNA";
        else
        {
            cout << "Pilihan tidak valid, silakan masukkan kembali." << endl;
            inputKewarganegaraan();
        }
    }

public:
    void input();
    void display();
};

void KTP::input()
{
    cout << "==================== Input KTP ====================" << endl;

    cout << "Provinsi\t\t: ";
    getline(cin, provinsi);
    cout << "Kabupaten\t\t: ";
    getline(cin, kabupaten);
    inputNik();
    cin.ignore();
    cout << "Nama\t\t\t: ";
    getline(cin, nama);
    cout << "Tempat lahir\t\t: ";
    cin >> tempat;
    inputTanggalLahir();
    cin.ignore();
    inputJenisKelamin();
    cout << "Golongan darah\t\t: ";
    getline(cin, golonganDarah);
    cout << "Dusun/Kampung\t\t: ";
    getline(cin, alamat);
    cout << "RT (3 digit)\t\t: ";
    cin >> rt;
    cout << "RW (3 digit)\t\t: ";
    cin >> rw;
    cin.ignore();
    cout << "Kelurahan/Desa\t\t: ";
    getline(cin, kelurahan);
    cout << "Kecamatan\t\t: ";
    getline(cin, kecamatan);
    inputAgama();
    inputStatusPerkawinan();
    cout << "Pekerjaan\t\t: ";
    getline(cin, pekerjaan);
    inputKewarganegaraan();
    cout << "Berlaku hingga\t\t: ";
    getline(cin, berlaku);
    cout << endl;
}

void KTP::display()
{
    system("cls");
    cout << "=============================================================" << endl;
    cout << "\t\tPROVINSI " << provinsi << endl;
    cout << "\t\tKABUPATEN " << kabupaten << endl;
    cout << "=============================================================" << endl;
    cout << "NIK\t\t\t: " << nik << endl;
    cout << "Nama\t\t\t: " << nama << endl;
    cout << "Tempat/Tgl Lahir\t: " << tempat << ", " << tanggal << "-" << bulan << "-" << tahun << endl;
    cout << "Jenis Kelamin\t\t: " << kelamin << "\t\tGol. Darah: " << golonganDarah << endl;
    cout << "Alamat\t\t\t: " << alamat << endl;
    cout << "\tRT/RW\t\t: " << rt << "/" << rw << endl;
    cout << "\tKel/Desa\t: " << kelurahan << endl;
    cout << "\tKecamatan\t: " << kecamatan << endl;
    cout << "Agama\t\t\t: " << agama << endl;
    cout << "Status Perkawinan\t: " << status << endl;
    cout << "Pekerjaan\t\t: " << pekerjaan << endl;
    cout << "Kewarganegaraan\t\t: " << kewarganegaraan << endl;
    cout << "Berlaku Hingga\t\t: " << berlaku << endl;
    cout << "=============================================================" << endl;
}

int main()
{
    KTP ktp;
    ktp.input();
    ktp.display();
    return 0;
}