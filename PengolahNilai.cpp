#include <iostream>
using namespace std;

const int MAX_PESERTA = 50;
const int MAX_MAPEL = 15;
int index;
int pilih;
string peserta;

struct Peserta {
    string nama;
    int nilai[MAX_MAPEL];
};

struct Maxmin {
    string pesertaMax;
    string pesertaMin;
    int max;
    int min;
};

Maxmin Maximin;
string daftarMapel[MAX_MAPEL] =
    {"B. Indonesia","Matematika","B. Inggris","IPA      ","IPS      "};

Peserta dataPeserta[MAX_PESERTA] =
    {
        {"Rama", {89,75,78,85,89}},
        {"Dio",{87,78,88,76,67}},
        {"Reva",{92,92,88,88,90}},
        {"Sona",{78,77,65,70,77}},
        {"Riski",{78,87,67,77,65}},
        {"Maulana",{82,84,78,78,90}},
        {"Nana",{95,88,78,88,90}},
        {"Rafli",{87,89,88,95,95}},
        {"Kamal",{88,87,89,77,78}},
        {"Sulis",{89,95,88,79,85}},
    };

int jumlahPeserta(){
    int total = 0;
    for(int i = 0; i < MAX_PESERTA; i++){
        if(!dataPeserta[i].nama.empty()){
            total++;
        } else {
            break;
        }
    }
    return total;
}

int jumlahMapel(){
    int total = 0;
    for(int i = 0; i < MAX_MAPEL; i++){
        if(!daftarMapel[i].empty()){
            total++;
        } else {
            break;
        }
    }
    return total;
}
void tampilPeserta(){
    int peserta = jumlahPeserta();
    for(int i = 0; i < peserta; i++){
        cout<<i+1<<". "<<dataPeserta[i].nama<<endl;
    }
};
void tampilMapel(){
    int jmm = jumlahMapel();
    for(int i=0; i < jmm;i++){
        cout<<i+1<<". "<<daftarMapel[i]<<endl;
    }
};


float rataRataPeserta (int index) {
    float total = 0;
    float rataRata;
    for(int j=0; j< jumlahMapel(); j++){
        total = total + dataPeserta[index].nilai[j];
    }
    return rataRata = total/jumlahMapel();
}

float rataRataMapel (int index){
    float total = 0;
    float rataRata;
    int jmls = jumlahPeserta();
    for(int j=0; j< jmls; j++){
        total = total + dataPeserta[j].nilai[index];
    }
    return rataRata = total/jmls;
}

float rataRataAll () {
    float total = 0;
    float rataRata;
    int jmls = jumlahPeserta();
    for(int i = 0; i < jmls; i++){
        for(int j = 0; j <jumlahMapel(); j++){
            total = total + dataPeserta[i].nilai[j];
        }
    }
    return rataRata=total/(jmls*jumlahMapel());
}

void cariMaxMin (Maxmin& hasil, int ind){
    int max = 0;
    int min = 100;
    string siswaMax = "none";
    string siswaMin = "none";
    int jmls = jumlahPeserta();
    for(int i = 0; i < jmls; i++){
        if (dataPeserta[i].nilai[ind] >max){
            max = dataPeserta[i].nilai[ind];
            siswaMax = dataPeserta[i].nama;
        }
    }
    hasil.pesertaMax = siswaMax;
    hasil.max = max;

    for(int i = 0; i < jmls; i++){
        if (dataPeserta[i].nilai[ind] < min){
            min = dataPeserta[i].nilai[ind];
            siswaMin = dataPeserta[i].nama;
        }
    }
    hasil.pesertaMin = siswaMin;
    hasil.min = min; 
}

void tampilData(){
    int jmlh = jumlahPeserta();
    int jmm = jumlahMapel();

    cout<<"Nama Peserta\t";
    for(int i = 0; i < jmm; i++){
        cout<<daftarMapel[i]<<"\t";
    } 
    cout<<"Rata-rata";
    cout<<endl;
    for(int j = 0; j < jmlh ;j++){
        cout<<dataPeserta[j].nama<<"\t\t";
        for(int k = 0; k < jmm; k++){
            cout<<dataPeserta[j].nilai[k]<<"\t\t";
        }
        cout<<rataRataPeserta(j);
        cout<<endl;
    }
    cout<<endl;
    cout<<"Rata-rata\t";
    for (int i = 0; i<jumlahMapel(); i++){
        cout<<rataRataMapel(i)<<"\t\t";
    }
    cout<<rataRataAll()<<endl;
    cout<<"Nilai Max\t";
    for(int i = 0; i<jumlahMapel();i++){
        cariMaxMin(Maximin,i);
        cout<<Maximin.max<<"\t\t";
    }
    cout<<endl;
    cout<<"Nilai Min\t";
    for(int i = 0; i<jumlahMapel();i++){
        cariMaxMin(Maximin,i);
        cout<<Maximin.min<<"\t\t";
    }
    cout<<endl;
};

void dataPerMapel(){
    int jmls = jumlahPeserta();
    cout<<"Mata Pelajaran :"<<endl;
    tampilMapel();
    cout<<endl;
    cout<<"Pilih mapel :";
    cin>>index;

    while(index < 1 || index > jumlahMapel() || cin.fail()){
        cin.clear(); cin.ignore();
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>index;
    }
    index = index-1;
    cout<<"> Mata Pelajaran dipilih : "<<daftarMapel[index]<<endl;
    for(int i = 0; i < jmls; i++){
        cout<<dataPeserta[i].nama<<"\t: "<<dataPeserta[i].nilai[index]<<endl;
    }
}

//  ================== CRUD ================

void tambahPeserta(string pesertabaru){
    int jmls = jumlahPeserta();
    dataPeserta[jmls].nama = pesertabaru;
    for(int i = 0; i<jumlahMapel();i++){
        dataPeserta[jmls].nilai[i] = 0;
    }
    cout<<endl;
    cout<<"Peserta berhasil ditambahkan........"<<endl;
}

void inputNilai(){
    int jmls = jumlahPeserta();
    int nilai;
    tampilPeserta();
    cout<<"Pilih Peserta Yang Akan Diinput :"<<endl;
    cin >> index; cout<<endl;
    
    while(index < 1 || index > jumlahPeserta() || cin.fail())
    {   cin.clear(); cin.ignore();
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>index;
    }
    index = index-1;
    for(int i = 0; i<jumlahMapel(); i++){
        cout<<daftarMapel[i]<<" : ";
        cin>>nilai;
        while(nilai < 0 || nilai > 100 || cin.fail())
        {
            cin.clear(); cin.ignore();
            cout<<"Input Salah!, ulangi ... : ";
            cin>>nilai;
        }
        dataPeserta[index].nilai[i] = nilai;
        cout<<endl;
    }
    cout<<"Input Nilai Berhasil......"<<endl;
}

void updateData(){
    string namaBaru;
    int nilai;
    int pilih;
    char toggle;

    tampilPeserta();
    cout<<endl;

    cout<<"Pilih Peserta Yang Ingin Diupdate : ";
    cin>>index;
    cout<<endl;
    while(index < 1 || index > jumlahPeserta() || cin.fail())
    {   cin.clear(); cin.ignore();
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>index;
    }
    index = index-1;

    cout<<dataPeserta[index].nama<<endl;
    cout<<"Apakah nama akan diubah? (y/n): ";
    cin>>toggle;
    while((toggle != 'y'  && toggle != 'n') || cin.fail()){
        cin.clear(); cin.ignore();
        cout<<"Masukkan anda salah! ulangi : ";
        cin>>toggle;
    }

    if(toggle == 'y'){
        cout<<"Masukkan nama baru: ";
        cin>>namaBaru;
        cout<<endl;
        dataPeserta[index].nama = namaBaru;
        cout<<"Nama berhasil diubah!"<<endl;
    } else if (toggle == 'n'){
        cout<<"Apakah nilai akan diubah? (y/n): ";
        cin>>toggle;

        while((toggle != 'y'  && toggle != 'n') || cin.fail()){
        cin.clear(); cin.ignore();
        cout<<"Masukkan anda salah! ulangi : ";
        cin>>toggle;
        }

        if( toggle == 'y'){
            for(int i = 0; i < jumlahMapel(); i++){
                cout<<i+1<<". "<<daftarMapel[i]<<" : "<<dataPeserta[index].nilai[i]<<endl;        
            }
            cout<<"Pilih Mapel : "; cin>>pilih;
            cout<<"Masukkan nilai : "; cin>>nilai;
            dataPeserta[index].nilai[pilih-1] = nilai;
            cout<<"Nilai berhasil diubah!"<<endl;
        } else if ( toggle == 'n'){
            cout<<"Tidak ada perubahan!"<<endl<<endl;
        }
    }
}


void deleteData(){
    int jmlh = jumlahPeserta();
    char toggle;
    tampilPeserta(); cout<<endl;
    cout<<"Pilih peserta yang ingin dihapus : ";
    cin>>index; cout<<endl;
    while(index < 1 || index > jumlahPeserta() || cin.fail())
    {   cin.clear(); cin.ignore();
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>index;
    }
    index = index-1;
    cout<<"Apakah data peserta "<<dataPeserta[index].nama<<" akan dihapus? (y/n) :";
    cin>>toggle;
    while((toggle != 'y'  && toggle != 'n') || cin.fail()){
        cin.clear(); cin.ignore();
        cout<<"Masukkan anda salah! ulangi : ";
        cin>>toggle;
    }
    if(toggle == 'y'){
        for(int i = index; i <= jmlh ; i++){
            dataPeserta[i].nama = dataPeserta[i+1].nama;
            for(int j = 0; j<jumlahMapel(); j++){
                dataPeserta[i].nilai[j] = dataPeserta[i+1].nilai[j];
            }
        }
    }
    cout<<"Data berhasil dihapus"<<endl;
}

void tambahMapel(){
    int jmlh = jumlahMapel();
    int jms = jumlahPeserta();
    char mapelnew[15];
    cout<<"Masukkan Nama Mapel Baru : ";
    cin>>mapelnew;
    string mapel = mapelnew;
    daftarMapel[jmlh] = mapel;
    for(int i = 0; i < jms; i++){
        dataPeserta[i].nilai[jmlh] = 0;
    }
    cout<<endl<<"Mapel Baru Berhasil Ditambahkan...."<<endl;

}

void deleteMapel(){
    int jmlh = jumlahMapel();
    int jms = jumlahPeserta();
    char toggle;
    tampilMapel();
    cout<<"Pilih Mapel Yang Akan Dihapus : ";
    cin>>index;
    while(index < 1 || index > jmlh || cin.fail())
    {   cin.clear(); cin.ignore();
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>index;
    }
    index = index-1; cout<<endl;
    cout<<"Apakah Yakin Mapel "<<daftarMapel[index]<<" akan dihapus ? (y/n) ";
    cin>>toggle;
    while((toggle != 'y'  && toggle != 'n') || cin.fail()){
        cin.clear(); cin.ignore();
        cout<<"Masukkan anda salah! ulangi : ";
        cin>>toggle;
    }
    cout<<endl;
    if(toggle == 'y'){
        for(int i = 0; i < jms ; i++){
            dataPeserta[i].nilai[index] = 0;
            for(int j = index; j <= jmlh; j++){
                dataPeserta[i].nilai[j] = dataPeserta[i].nilai[j+1];
            }
        }
        for(int k = index; k <= jmlh ; k++){
            daftarMapel[k] = daftarMapel[k+1];
        }
        cout<<"Data berhasil dihapus........"<<endl;
    } else if (toggle == 'n'){
        cout<<"Tidak ada perubahan......"<<endl;
    }

}
int main () {
    menu:
    cout<<"========================= DASHBOARD ======================"<<endl;
    tampilData();
    cout<<endl;
    cout<<endl<<"============== DAFTAR MENU ==================="<<endl;
    cout<<"1. Filter"<<endl;
    cout<<"2. Tambah Peserta Baru"<<endl;
    cout<<"3. Input Nilai Peserta"<<endl;
    cout<<"4. Update Peserta"<<endl;
    cout<<"5. Delete Peserta"<<endl;
    cout<<"6. Tambah Mapel"<<endl;
    cout<<"7. Delete Mapel"<<endl;
    cout<<"99. EXIT"<<endl;

 
    cout<<"Pilih menu : "; cin>>pilih;
    while((pilih < 1 || (pilih > 8 && pilih != 99)) || cin.fail()){
        cin.clear(); cin.ignore(1000, '\n');
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>pilih;
    }
    cout<<endl;
switch(pilih){

case 1:
    search:
    cout<<"====== FILTER ======"<<endl;
    cout<<"1. Berdasarkan Peserta"<<endl;
    cout<<"2. Berdasarkan Mapel"<<endl;
    cout<<"3. Kembali"<<endl;
    cout<<"Pilih : ";
    cin>>pilih;
    while(pilih < 1 || pilih > 3  || cin.fail()){
        cin.clear(); cin.ignore(1000, '\n');
        cout<<"Pilihan Salah!, ulangi ... : ";
        cin>>pilih;
    }
    cout<<endl;
    switch(pilih){
        case 1:
            cout<<endl;
            cout<<"==== Daftar Peserta ====="<<endl;
            tampilPeserta(); cout<<endl;

            cout<<"Pilih peserta : ";
            cin>>index;
            while(index < 1 || index > jumlahPeserta() || cin.fail()){
                cin.clear(); cin.ignore();
                cout<<"Pilihan Salah!, ulangi ... : ";
                cin>>index;
            }
            index = index-1;cout<<endl<<endl;

            cout<<"Nilai Permapel dari : "<<dataPeserta[index].nama<<endl;
            for(int i = 0; i<jumlahMapel();i++){
                cout<<daftarMapel[i]<<"\t: ";
                cout<<dataPeserta[index].nilai[i]<<endl;
            } cout<<endl;

            goto search;
        case 2:
            cout<<"=== Daftar Mapel ==="<<endl;
            tampilMapel();
            cout<<endl;
            cout<<"Pilih Mapel : ";
            cin>>index;
            while(index < 1 || index > jumlahMapel() || cin.fail()){
                cin.clear(); cin.ignore();
                cout<<"Pilihan Salah!, ulangi ... : ";
                cin>>index;
            }
            index = index-1;
            cout<<daftarMapel[index];
            cout<<endl<<endl;
             cout<<"Nilai Peserta dari : "<<daftarMapel[index]<<endl;
            for(int i = 0; i<jumlahPeserta();i++){
                cout<<dataPeserta[i].nama<<"\t\t";
                cout<<dataPeserta[i].nilai[index]<<endl;
            }
            cout<<endl;
            goto search;
        case 3:
            goto menu;
    }

goto menu;

case 2:
    cout<<"==== Tambah Peserta Baru ===="<<endl<<endl;
    cout<<"Masukkan Nama Peserta : "<<endl;
    cin>>peserta;
    while(cin.fail()){
        cin.clear();cin.ignore();
        cout<<"Masukkan Anda Salah, Ulangi......!"<<endl;
        cin>>peserta;
    }
    tambahPeserta(peserta);
    goto menu;

case 3:
    cout<<"=== Input Nilai ===";
    inputNilai();
    goto menu;

case 4:
    cout<<"=== Update Data Peserta === "<<endl;

    updateData();
    goto menu;

case 5:
    cout<<"=== Delete Peserta ==="<<endl<<endl;
    deleteData();
    goto menu;

case 6:
    cout<<"=== Tambah Mapel ==="<<endl;
    tambahMapel();
    goto menu;
case 7:
    cout<<"=== Delete Mapel ==="<<endl;
    deleteMapel();
    goto menu;
case 99:
cout<<"Anda Keluar dari Program............."<<endl<<endl;
    break;
    }
    return 0;
}
