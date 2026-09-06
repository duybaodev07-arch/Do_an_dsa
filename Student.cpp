#include "Student.h";
#include "MyVector.h"
#include<iostream>
#include<limits>
using namespace std;

NodeSV* taoNodeSv(const SinhVien &sv) {
    NodeSV* newNode = new NodeSV;
    newNode->data = sv;
    return newNode;
}
NodeSV* timSV(const DSSV &ds, string maSV) {
    NodeSV* find = ds.head;
    while(find) {
        if(find->data.maSV == maSV) return find;
    }
    return nullptr;
}
bool dungTruoc(const SinhVien& a, const SinhVien& b) {
    if (a.ten != b.ten)
        return a.ten < b.ten;

    if (a.ho != b.ho)
        return a.ho < b.ho;

    return a.maSV < b.maSV;
}
void themSV(DSSV &ds, const SinhVien &sv) {
    NodeSV* newNode = taoNodeSV(sv);
    if(ds.head == nullptr) {
        ds.head = ds.tail = newNode;
        return;
    }
    // newSV dung truoc head
    if(dungTruoc(sv, ds.head->data)) {
        newNode-> next = ds.head;
        ds.head = newNode;
        return;
    }
    // tim vi tri chen
    NodeSV* cur = ds.head;
    while(cur->next && !dungTruoc(sv, cur->next->data)) {
        // lap neu node tiep theo ko nullptr va newSV.name dung sau curName
        cur = cur-> next;
    }
    newNode-> next = cur->next;
    cur-> next = newNode;
    // neu chen vao node cuoi
    if(newNode-> next == nullptr) ds.tail = newNode;
}
bool xoasSV(DSSV &ds, string maSV) {
    if(!ds.head) return false; // chua xoa
    if(ds.head->data.maSV == maSV) {
        NodeSV* temp = ds.head;
        ds.head = ds.head-> next;
        delete temp;
        if(ds.head == nullptr) ds.tail = nullptr;
        return true; // da xoa
    }
    NodeSV* cur = ds.head;
    while(cur-> next && cur->next->data.maSV != maSV) {
        // dung o truoc node can xoa
        cur = cur-> next;
    }
    if(cur-> next == nullptr) return false; // chua xoa
    NodeSV* tmp = cur-> next;
    cur-> next = tmp-> next;
    if(tmp == ds.tail) {
        ds.tail = cur;
    }
    delete tmp;
    return true; // da xoa
}
void nhapThongTinSua(SinhVien& sv) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // xoa buffer
    cout << "Ho: "; getline(cin, sv.ho);
    cout << "Ten: "; getline(cin, sv.ten);
    cout << "Phai: "; getline(cin, sv.phai);
    cout << "So DT: "; getline(cin, sv.soDT);
}

bool suaSV(DSSV &ds, const string &maSV) {
    NodeSV* cur = timSV(ds, maSV);
    if(cur == nullptr) return false; // sua ko thanh cong
    SinhVien svMoi = cur->data;
    nhapThongTinSua(svMoi);
    xoaSV(ds, maSV);
    themSV(ds, svMoi);
    return true; // sua xong
}

