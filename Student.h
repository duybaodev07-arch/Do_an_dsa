#ifndef STUDENT_H
#define STUDENT_H
#include<string>

struct SinhVien {
    std::string maSV;
    std::string ho;
    std::string ten;
    std::string phai;
    std::string soDT;
};

struct NodeSV {
    SinhVien data;
    NodeSV* next = nullptr;
};

struct DSSV {
    NodeSV* head = nullptr;
    NodeSV* tail = nullptr;
};  

NodeSV*taoNodeSV(const SinhVien& sv);
NodeSV* timSV(const DSSV &ds, std::string maSV);
void themSV(DSSV &ds, const SinhVien &sv);
bool xoaSV(DSSV &ds, std::string maSV);
bool suaSv(DSSV &ds, std::string maSV);
void xuatDSSV(const DSSV &ds);
void xuatDSSVTheoMa(DSSV& ds);
/*
QUY TẮC SẮP XẾP DANH SÁCH SINH VIÊN

- Danh sách sinh viên luôn được sắp xếp tăng dần theo TEN.
- Nếu trùng TEN → xét HO.
- Nếu trùng cả TEN và HO → xét MASV.
*/
#endif