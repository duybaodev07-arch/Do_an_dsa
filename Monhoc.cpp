#include "MonHoc.h"
using namespace std;

NodeMH* taoNodeMH(const MonHoc& mh) {
    NodeMH* newNode = new NodeMH;
    newNode->data = mh;
    return newNode;
}
NodeMH* timMH(NodeMH* root, const string& maMH) {
    if(root == nullptr) 
        return nullptr;
    if(root->data.maMH == maMH) 
        return root;
    NodeMH* result = timMH(root-> left, maMH);
    if(result != nullptr) 
        return result;
    return timMH(root-> right, maMH);
}
