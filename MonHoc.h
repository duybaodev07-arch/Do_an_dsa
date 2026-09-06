#ifndef MONHOC_H
#define MONHOC_H
#include<string>
struct MonHoc {
    std::string maMH;
    std::string tenMH;
    int soTCLT = 0;
    int soTCTH = 0;
};
struct NodeMH {
    MonHoc data;
    NodeMH* left = nullptr;
    NodeMH* right = nullptr;
};

struct TreeMH {
    NodeMH* root = nullptr;
};
NodeMH* taoNodeMH(const MonHoc& mh);
NodeMH* timMH(TreeMH& tree, const std::string& maMH);
bool themMH(TreeMH& tree, const MonHoc& mh);
bool xoaMH(TreeMH& tree, const std::string& maMH);
bool suaMH(TreeMH& tree, const std::string& maMH);
void nhapMH(MonHoc& mh);
void xuatMH(const MonHoc& mh);
void xuatDSMH(TreeMH& tree);
#endif