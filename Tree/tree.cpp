#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }

    TreeNode* buildTree(TreeNode* root)
    {
        cout<<"Enter the value of the node: ";
        int data;
        cin>>data;
        
        if(data==-1)
        {
            return nullptr;
        }
        root=new TreeNode(data);
        cout<<"Enter the left value for "<<data<<": ";
        root->left=buildTree(root->left);
        cout<<"Enter the right value for "<<data<<": ";
        root->right=buildTree(root->right);
        return root;
    }

    void inorder(TreeNode* root)
    {
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
    }
    void preorder(TreeNode* root)
    {
        if(root==nullptr) return;
        cout<<root->val;
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(TreeNode* root)
    {
        if(root==nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val; 
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                level.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main()
{
    TreeNode* root=nullptr;
    root=root->buildTree(root);
    cout<<"Inorder Traversal:"<<endl;
    root->inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal:"<<endl;
    root->preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal:"<<endl;
    root->postorder(root);
    cout<<endl;
    cout<<"Level Order Traversal:"<<endl;
    vector<vector<int>> levels = root->levelOrder(root);
    for(auto level:levels)
    {
        for(auto it: level)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}























































// #include<iostream>
// using namespace std ;

// class Node
// {
//     public:
//     int val;
//     Node* left;
//     Node* right;
    
//     Node(int data)
//     {
//         val=data;
//         left=nullptr;
//         right=nullptr;
//     }

//     Node* buildTree(Node* root)
//     {
//         cout<<"Enter the value to enter:"<<endl;
//         int data;
//         cin>>data;
//         if(data==-1)
//         {
//             return nullptr;
//         }
//         root=new Node(data);
//         cout<<"Enter the value to enter to the left of"<<data<<":"<<endl;
//         root->left=buildTree(root->left);
//         cout<<"Enter the value to enter to the right of"<<data<<":"<<endl;
//         root->right=buildTree(root->right);
//         return root;
//     }

//     void printInorder(Node* root)
//     {
//         if(root==nullptr)
//         {
//             return;
//         }
//         printInorder(root->left);
//         cout<<root->val<<"->";
//         printInorder(root->right);
//     }
    
//     void printPreorder(Node* root)
//     {
//         if(root==nullptr)
//         {
//             return;
//         }
//         cout<<root->val<<"->";
//         printPreorder(root->left);
//         printPreorder(root->right);
//     }
    
//     void printPostorder(Node* root)
//     {
//         if(root==nullptr)
//         {
//             return;
//         }
//         printPostorder(root->left);
//         printPostorder(root->right);
//         cout<<root->val<<"->";
//     }
// };

// int main() {
//     Node *root=nullptr;
//     root=root->buildTree(root);
//     cout<<"In Order:"<<endl;
//     root->printInorder(root);
//     cout<<endl;
//     cout<<"Pre Order:"<<endl;
//     root->printPreorder(root);
//     cout<<endl;
//     cout<<"Post Order:"<<endl;
//     root->printPostorder(root);
//     cout<<endl;
//     return 0 ;
// }




