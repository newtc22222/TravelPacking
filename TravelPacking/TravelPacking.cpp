// TravelPacking.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Chuong trinh sap xep hanh ly
// Chuc nang co ban: liet ke, them, sua, xoa, tim kiem do dung
// Chuc nang chinh: lua chon va goi y cac kieu sap xep phu hop dua tren giai thuat Di truyen
// Co the luu tru du lieu trong file item.txt -> Load len mang struct de dung
// 

#include <iostream>
#define MAX_ITEM 200

using namespace std;

string path = "item.txt";

struct item {
    string name;
    float price;
    float weight;
    float height;
    float width;
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

void sample_item(item it[]) // Lay du lieu mau tu file item.txt dua vao struct
{
    
}

void LuuThongTinMoi(item it[]) // Luu thong tin da co thay doi vao file
{

}

void themItem() // Them du lieu hoan toan moi
{

}

void suaItem() // Tim kiem vat dung theo ten, sau do thuc hien chinh sua
{

}

void xoaItem() // Tim kiem vat dung, sau do xoa vat dung
{

}

void InThongTin(item it) {
    cout << "Ten vat dung: " << it.name;
    cout << "Gia thanh: " << it.price;
    cout << "Can nang: " << it.weight;
    cout << "Chieu dai: " << it.height;
    cout << "Chieu rong: " << it.width;
}

void LietKeItem(item it[], int size) {
    for (int i = 0; i < size; i++) {

    }
}

void TimKiemItem() // Tim kiem theo ten (hoac lua chon tim kiem theo gia/can nang/chieu dai/chieu rong)
{

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
void NhapKhongGian(int& canNang) {
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
    cout << "|   7. Thoat khoi chuong trinh                       |" << endl;
    cout << "------------------------------------------------------" << endl;
}

int main()
{
    // Thuoc tinh duoc cai dat
    float chieuDai, chieuRong, canNang, tongGiaTri;

    // Khai bao mang do dung
    item it[MAX_ITEM]; // Nho khai bao contructor mac dinh
    sample_item(it);

    return 0;
}

