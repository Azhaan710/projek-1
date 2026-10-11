#include <iostream>
#include <string>
#include <vector>
using std::cout, std::vector;

void pilihanMenu();
void masukanList(std::string &barang, vector<std::string> &belanjaan);
void keluarkanList(vector<std::string> &belanjaan);
void BerikanList(vector<std::string> &belanjaan);
void rapihkanList(vector<std::string> &belanjaan);
void cetakListSorting(vector<std::string> &belanjaan);


int main()
{
    vector<std::string> belanjaan;
    std::string barang;

    int pilihan;
    do{
        pilihanMenu();
        std::cin>>pilihan;
        cout<<std::endl;
        std::cin.ignore();
        switch(pilihan){
            case 1 :
                masukanList(barang, belanjaan);
                break;
            case 2 :
                keluarkanList(belanjaan);
                break;
            case 3 :
                BerikanList(belanjaan);
                break;
            case 4 :
                rapihkanList(belanjaan);
                cetakListSorting(belanjaan);
                break;
            case 5 :
                cout<<"Program Selesai.\n";
                break;
            default :
                cout<<"angka menu tidak sesuai!\n";
                break;
        }
    }while(pilihan != 5);

    return 0;
}
void pilihanMenu()
{
    cout<<"Menu list pembelanjaan\n";
    cout<<"1. Tambah list belanjaan\n";
    cout<<"2. kurangi list belanjaan\n";
    cout<<"3. berikan list-list belanjaan\n";
    cout<<"4. rapihkan list belanjaan sesuai alpabet\n";
    cout<<"5. keluar program\n";
    cout<<"pilih menu : ";
}
void masukanList(std::string &barang, vector<std::string> &belanjaan)
{
    cout<<"Masukan barang belanjaan\n";
    getline(std::cin, barang);
    belanjaan.push_back(barang);
    cout<<"belanjaan berhasil dimasukkan\n\n";
}
void keluarkanList(vector<std::string> &belanjaan)
{
    if(belanjaan.empty())
    {
        cout<<"list belanja masih kosong\n";
    }
    else
    {
        int nomorBarang;
        int size = belanjaan.size();
        cout<<"total list kamu ada : "<<size<<std::endl;
        cout<<"masukkan nomor barang yang ingin dihapus\n";
        std::cin>>nomorBarang;
        if(nomorBarang >= 1 && nomorBarang <= size)
        {
            cout<<"barang '"<<belanjaan[nomorBarang-1]<<"' dihapus\n";
            belanjaan.erase(belanjaan.begin() + nomorBarang - 1);
            cout<<std::endl;
        }
        else
        {
            cout<<"nomor anda invalid.\n";
            cout<<"proses hapus dibatalkan\n\n";
        }
    }
}
void BerikanList(vector<std::string> &belanjaan)
{
    if(belanjaan.empty())
    {
        cout<<"list belanja masih kosong\n";
    }
    else
    {
        for(int i = 0; i < belanjaan.size(); i++)
        {
            cout<<i+1<<". "<<belanjaan[i]<<std::endl;
        }
        cout<<std::endl;
    }
}
void rapihkanList(vector<std::string> &belanjaan)
{
    int n = belanjaan.size();
    bool pertukaran;
    for(int i = 0; i < n; i++)
    {
        pertukaran = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(belanjaan[j]>belanjaan[j+1]){
                std::swap(belanjaan[j], belanjaan[j+1]);
                pertukaran = true;
            }
        }
        if(!pertukaran){
            break;
        }
    }
}
void cetakListSorting(vector<std::string> &belanjaan)
{
    for(std::string i : belanjaan)
    {
        cout<<i<<std::endl;
    }
    cout<<std::endl;
}
