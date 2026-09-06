#include "Lop.h"
#include<iostream>
#include<limits>
using namespace std;

int timLop(DanhSachLop& ds, const string maLop) {
    for(int i = 0; i < ds.soLuong; i++) {
        if(ds.data[i].maLop == maLop) return i;
    }
    return -1;
}
bool themLop(DanhSachLop &ds, const Lop& lop) {
    if(ds.soLuong >= MAX_LOP) return false; // het cho
    if(timLop(ds, lop.maLop) != -1) {
        // check trùng
        return false;
    }
    ds.data[ds.soLuong] = lop;
    ds.soLuong++;
    return true; // them thanh cong
}
bool xoaLop(DanhSachLop &ds, const string &maLop) {
    int index = timLop(ds, maLop);
    if(index == -1) return false; // ko tim thay
    for(int i = index; i < ds.soLuong -1; i++) {
        ds.data[i] = ds.data[i + 1];
    }
    ds.soLuong--;
    return true; // xoa thanh cong
    // mang tinh ko can delete
}
void nhapLop(Lop& lop) {
    cout << "Nhap ten lop: "; getline(cin, lop.tenLop);
    cout << "Nhap ma lop: "; getline(cin, lop.maLop);
}
bool suaLop(DanhSachLop &ds, const string& maLop) {
    int index = timLop(ds, maLop);
    if(index == -1) return false;
    cout << "Nhap ten lop moi: "; // ko sửa maLop
    getline(cin, ds.data[index].maLop);
    return true;
}
