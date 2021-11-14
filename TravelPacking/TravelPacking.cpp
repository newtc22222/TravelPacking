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
};

void sample_item(item[] it) {

}

void addItem() {

}

void suaItem() {

}

void xoaItem() {

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
    item it[MAX_SIZE];
    sample_item(it);

    return 0;
}

