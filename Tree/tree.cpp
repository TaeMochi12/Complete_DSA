#include<iostream>
using namespace std ;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        val=data;
        left=nullptr;
        right=nullptr;
    }

    Node* buildTree(Node* root)
    {
        cout<<"Enter the value to enter:"<<endl;
        int data;
        cin>>data;
        if(data==-1)
        {
            return nullptr;
        }
        root=new Node(data);
        cout<<"Enter the value to enter to the left of"<<data<<":"<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter the value to enter to the right of"<<data<<":"<<endl;
        root->right=buildTree(root->right);
        return root;
    }

    void printInorder(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        printInorder(root->left);
        cout<<root->val<<"->";
        printInorder(root->right);
    }
    
    void printPreorder(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        cout<<root->val<<"->";
        printPreorder(root->left);
        printPreorder(root->right);
    }
    
    void printPostorder(Node* root)
    {
        if(root==nullptr)
        {
            return;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->val<<"->";
    }
};

int main() {
    Node *root=nullptr;
    root=root->buildTree(root);
    cout<<"In Order:"<<endl;
    root->printInorder(root);
    cout<<endl;
    cout<<"Pre Order:"<<endl;
    root->printPreorder(root);
    cout<<endl;
    cout<<"Post Order:"<<endl;
    root->printPostorder(root);
    cout<<endl;
    return 0 ;
}




