#ifndef LOP_H
#define LOP_H
#include "Student.h"
#include<string>

const int MAX_LOP = 10000;
struct Lop {
    std::string maLop;
    std::string tenLop;
    DSSV dsSV;
};

struct DanhSachLop {
    Lop data[MAX_LOP];
    int soLuong = 0;
};
int timLop(DanhSachLop& ds, const string& maLop); // return idx
bool themLop(DanhSachLop &ds, const Lop &lop);
bool xoaLop(DanhSachLop& ds, const string& maLop);
void nhapLop(Lop& lop); // dùng sửa lớp
bool suaLop(DanhSachLop& ds, const string& maLop);
void xuatLop(const Lop& lop);

#endif