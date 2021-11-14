// TravelPacking.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define MAX_ITEM 200

using namespace std;

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

void sample_item(item it[]) {
    
}

void themItem() {

}

void suaItem() {

}

void xoaItem() {

}

void SapXepItem() {

}

void LaiGhep() {

}

void DotBien() {

}

void ChonLoc() {

}

void GeneticFunction() {

}

void NhapKhongGian(int& canNang) {
    cout << "Nhap can nang ban co the mang theo: ";
    cin >> canNang;
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

