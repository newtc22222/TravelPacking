// TravelPacking.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Chuong trinh sap xep hanh ly
// Chuc nang co ban: liet ke, them, sua, xoa, tim kiem do dung
// Chuc nang chinh: lua chon va goi y cac kieu sap xep phu hop dua tren giai thuat Di truyen
// Co the luu tru du lieu trong file item.txt -> Load len mang struct de dung
// 

#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#define MAX_ITEM 1000

using namespace std;

string path = "item.txt";
int so_luong_item_hientai; //Bien quyet dinh so luong

struct item {
    string name; // ten goi
    float price; // gia thanh
    float weight; // can nang (g)
    float height; // chieu dai (cm)
    float width; // chieu ngang (cm)
    // Contructor: luu tru thong tin truc tiep
    item() {
        this->name = "Unknown";
        this->price = 0;
        this->weight = 0;
        this->height = 0;
        this->width = 0;
    }
    item(string name, float price, float weight, float height, float width) {
        this->name = name;
        this->price = price;
        this->weight = weight;
        this->height = height;
        this->width = width;
    }
};

void ClearScreen() {
    //cout << "\033[2J\033[1;1H"; // magic
    system("cls");
}

int length_of_array_item(item it[]) {
    unsigned int x = sizeof(it) / sizeof(it[0]);
    return x;
}

void du_lieu_mau(item it[]) // Hàm dùng để thêm dữ liệu cho việc test
{
    it[0] = item("Dark Nhan Tam", 60000, 260, 20.5, 14.5);
    it[1] = item("Ao thun mac trong", 100000, 120, 80, 50);
    it[2] = item("Ao khoac da", 100000, 600, 100, 90);
    it[3] = item("Ao mua nilong", 100000, 80, 80, 50);
    it[4] = item("Tat trong nha", 100000, 80, 80, 50);
    it[5] = item("So ghi chep a5", 100000, 240, 80, 50);
    it[6] = item("So ve phac hoa a4", 100000, 350, 80, 500);
    it[7] = item("Day nit Guchi", 15000000, 800, 80, 50);
    it[8] = item("Dong ho Rolex", 3000000000, 550, 10, 20);
    it[9] = item("Quan di boi", 80000, 100, 50, 70);
    it[10] = item("Quan jean", 400000, 420, 140, 80);
    it[11] = item("Dep lao", 100000, 240, 30, 15);
    it[12] = item("Ao khoac di bien", 300000, 180, 80, 50);
    it[13] = item("Vot bat hai san", 300000, 360, 80, 50);
    it[14] = item("May anh", 1000000, 420, 80, 50);
    so_luong_item_hientai = 15;
}

void sample_item(item it[]) // Lay du lieu mau tu file item.txt dua vao struct
{
    int line = 1, index = 0, item_index = 0;
    string Text;
    string item_value[5];
    ifstream MyReadFile(path);
    
    while (getline(MyReadFile, Text)) {
        item_value[index++] = Text;

        if (line != 1 && line % 5 == 0) {
            it[item_index].name = item_value[0];
            it[item_index].price = stof(item_value[1]);
            it[item_index].weight = stof(item_value[2]);
            it[item_index].height = stof(item_value[3]);
            it[item_index].width = stof(item_value[4]);
            item_index++;
            index = 0;
        }
        line++;
    }

    so_luong_item_hientai = item_index;
}

void LuuThongTinMoi(item it[]) // Luu thong tin da co thay doi vao file
{
    ofstream MyFile(path);

    for (int i = 0; i < so_luong_item_hientai; i++) {
        MyFile << it[i].name << endl;
        MyFile << it[i].price << endl;
        MyFile << it[i].weight << endl;
        MyFile << it[i].height << endl;
        MyFile << it[i].width << endl;
    }

    MyFile.close();
}

void themItem(item it[]) // Them du lieu hoan toan moi
{
    int n = so_luong_item_hientai;
    cout << "Nhap them san pham: " << endl;
    rewind(stdin);
    cout << "Nhap ten san pham can them :";
    getline(cin, it[n].name);
    cout << "Nhap gia thanh: ";
    cin >> it[n].price;
    cout << "Nhap can nang: ";
    cin >> it[n].weight;
    cout << "Nhap chieu cao: ";
    cin >> it[n].height;
    cout << "Nhap chieu rong: ";
    cin >> it[n].width;
    so_luong_item_hientai++;
}

void NhapThongTinMoi(string& newname, float& newprice, float& newweight, float& newheight, float& newwidth)
{
    rewind(stdin);
    cout << "\nNhap ten vat dung moi: ";
    getline(cin, newname);
    cout << "\nNhap gia thanh moi: ";
    cin >> newprice;
    cout << "\nNhap can nang moi: ";
    cin >> newweight;
    cout << "\nNhap chieu cao moi: ";
    cin >> newheight;
    cout << "\nNhap chieu rong moi: ";
    cin >> newwidth;
}

void suaItem(item it[]) // Tim kiem vat dung theo ten, sau do thuc hien chinh sua
{
    string x, newname;
    float newprice, newweight, newheight, newwidth;
    int tmp = 0;
    int n = so_luong_item_hientai;
    rewind(stdin);
    cout << " Nhap ten san pham muon sua: ";
    getline(cin, x);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (it[i].name == x)
        {
            cout << "Sua lai san pham thu " << i;
            NhapThongTinMoi(newname, newprice, newweight, newheight, newwidth); //goi ham nhap 1 san pham de nhap lai san pham
            it[i].name = newname;
            it[i].price = newprice;
            it[i].weight = newweight;
            it[i].height = newheight;
            it[i].width = newwidth;
            found = 1;
        }
    }
}

void xoa(item it[], int n, int tmp)
{
    for (int i = tmp; i < n; i++)
    {
        it[i] = it[i + 1];
    }
}

void xoaItem(item it[]) // Tim kiem vat dung, sau do xoa vat dung
{
    string x;
    int n = so_luong_item_hientai;
    cout << "Nhap ten san pham can xoa";
    rewind(stdin);
    getline(cin, x);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (it[i].name == x)
        {
            found = 1;
            xoa(it, n, i);
        }
    }
    if (found == 0)
    {
        cout << "\n san pham ko toi tai." << x;
    }
    else
    {
        cout << "\n Da xoa SV co ten = " << x;
        so_luong_item_hientai--;
    }
}

void InThongTin(item it) {
    cout << "Ten vat dung: " << it.name << endl;
    cout << "Gia thanh: " << it.price << endl;
    cout << "Can nang: " << it.weight << endl;
    cout << "Chieu dai: " << it.height << endl;
    cout << "Chieu rong: " << it.width << endl;
}

void LietKeItem(item it[], int size) {
    for (int i = 0; i < size; i++) {
        InThongTin(it[i]);
    }
}

void TimKiemTen(item it[], int n, string x)
{
    for (int i = 0; i < n; i++)
    {
        //if (it[i].name == x)
        //{
        //    InThongTin(it[i]);
        //}
        if (it[i].name.find(x) != string::npos) // Ten co chua chuoi x
        {
            InThongTin(it[i]);
        }
    }
}

void TimKiemGia(item it[], int n, float x)
{
    for (int i = 0; i < n; i++)
    {
        if (it[i].price == x)
        {
            InThongTin(it[i]);
        }
    }
}

void TimKiemCanNang(item it[], int n, float x)
{
    for (int i = 0; i < n; i++)
    {
        if (it[i].weight == x)
        {
            InThongTin(it[i]);
        }
    }
}

void TimKiemChieuDai(item it[], int n, float x)
{
    for (int i = 0; i < n; i++)
    {
        if (it[i].height == x)
        {
            InThongTin(it[i]);
        }
    }
}

void TimKiemChieuRong(item it[], int n, float x)
{
    for (int i = 0; i < n; i++)
    {
        if (it[i].width == x)
        {
            InThongTin(it[i]);
        }
    }
}

void TimKiemItem(item it[]) // Tim kiem theo ten (hoac lua chon tim kiem theo gia/can nang/chieu dai/chieu rong)
{
    int choose;
    int n = so_luong_item_hientai;
    string x;
    float t;
    bool tmp = true;
    while (tmp)
    {
        cout << " 1. Tim kiem theo ten. \n";
        cout << " 2. Tim kiem theo gia. \n";
        cout << " 3. Tim kiem theo can nang. \n";
        cout << " 4. Tim kiem theo chieu dai. \n";
        cout << " 5. Tim kiem heo chieu rong. \n";
        cout << " 0. Thoat chuong trinh. \n";
        cout << " Moi nhap lua chon \n";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            ClearScreen();
            cout << "\nNhap ten san pham ban can tim: ";
            rewind(stdin);
            getline(cin, x);
            TimKiemTen(it, n, x);
            break;
        }
        case 2:
        {
            ClearScreen();
            cout << "\nNhap gia can tim kiem: ";
            cin >> t;
            TimKiemGia(it, n, t);
            break;
        }
        case 3:
        {
            ClearScreen();
            cout << "\nNhap can nang can tim kiem: ";
            cin >> t;
            TimKiemCanNang(it, n, t);
            break;
        }
        case 4:
        {
            ClearScreen();
            cout << "\nNhap chieu dai can tim kiem: ";
            cin >> t;
            TimKiemChieuDai(it, n, t);
            break;
        }
        case 5:
        {
            ClearScreen();
            cout << "\nNhap chieu rong can tim kiem: ";
            cin >> t;
            TimKiemChieuRong(it, n, t);
            break;
        }
        case 0:
        {
            ClearScreen();
            tmp = false;
            break;
        }
        default:
        {
            cout << "\nKhong co chuc nang nay!" << endl;
            break;
        }
        }
    }
}

void SapXepItem() // Sap xep tuy y (theo lua chon cua nguoi dung)
{

}

// Giai thuat di truyen
void LaiGhep() {

}

void DotBien() {

}

void ChonLoc() {

}

void GeneticFunction() {

}

// Input cua nguoi dung
void NhapKhongGian(float& canNang) {
    cout << "Nhap can nang ban co the mang theo: ";
    cin >> canNang;
}

void intro() {
    cout << "------------------------------------------------------" << endl;
    cout << "|Chuong trinh sap xep hanh ly cho cac chuyen di choi!|" << endl;
    cout << "|   1. Liet ke cac vat dung co san                   |" << endl;
    cout << "|   2. Them mot vat dung                             |" << endl;
    cout << "|   3. Sua mot vat dung                              |" << endl;
    cout << "|   4. Xoa mot vat dung                              |" << endl;
    cout << "|   5. Tim kiem vat dung                             |" << endl;
    cout << "|   6. Sap xep va goi y                              |" << endl;
    cout << "|   Khac. Thoat khoi chuong trinh                    |" << endl;
    cout << "------------------------------------------------------" << endl;
}

int main()
{
    // Thuoc tinh duoc cai dat
    float canNang;
    int luaChon;
    bool flag = true; // Chay chuong trinh

    item *it = new item[MAX_ITEM];
    //du_lieu_mau(it);
    sample_item(it);

    while (flag) {
        intro();
        cout << "Moi ban nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon)
        {
        case 1:
            ClearScreen();
            LietKeItem(it, so_luong_item_hientai);
            break;
        case 2:
            ClearScreen();
            themItem(it);
            break;
        case 3:
            ClearScreen();
            suaItem(it);
            break;
        case 4:
            ClearScreen();
            xoaItem(it);
            break;
        case 5:
            ClearScreen();
            TimKiemItem(it);
            break;
        case 6:
            ClearScreen();
            NhapKhongGian(canNang);
            GeneticFunction();
            break;
        default:
            flag = false;
            break;
        }
    }

    LuuThongTinMoi(it);
    delete[] it;
    it = nullptr;
    return 0;
}

