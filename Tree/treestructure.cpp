#include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};