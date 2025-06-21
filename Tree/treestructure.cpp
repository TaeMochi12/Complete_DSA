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

void inorder(treeNode* root)
{
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}

void preorder(treeNode* root)
{
    if(root==nullptr) return;
    cout<<root->data<<"->" ;
    preorder(root->left);
    preorder(root->right);
}

void postorder(treeNode* root)
{
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";
}

void levelorder(treeNode* root,vector<vector<int>>&ans)
{
    if(root==nullptr) return;
    queue<treeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++)
        {
            treeNode* top=q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            level.push_back(top->data);
        }
        ans.push_back(level);
    }
}
void print_levelorder(treeNode* root)
{
    if(root==nullptr) return;
    queue<treeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            treeNode* top=q.front();
            q.pop();
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
            cout<<top->data<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    treeNode* root=new treeNode(1);
    root->left=new treeNode(2);
    root->left->left=new treeNode(4);
    root->left->right=new treeNode(5);
    root->right=new treeNode(3);
    root->right->left=new treeNode(6);
    root->right->right=new treeNode(7);

    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Level Order Traversal:"<<endl;
    print_levelorder(root);
}

