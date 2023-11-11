#include<iostream>
#define SPACE 10
using namespace std ;

class TreeNode
{
    public:
    int value;
    TreeNode* left;
    TreeNode *right;

    TreeNode()
    {
        value=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v)
    {
        value=v;
        left=NULL;
        right=NULL;
    }
};

class BST
{
    public:
    TreeNode *root;
    BST()
    {
        root=NULL;
    }
    bool isEmpty()
    {
        if(root==NULL) return true;
        else return false;    
    }
    void insertNode(TreeNode *new_node)
    {
        if(root==NULL)
        {
            root=new_node;
            cout<<"Value Inserted as root node"<<endl;
        }
        else
        {
            TreeNode *temp=root;
            while(temp!=NULL)
            {
                if(new_node->value==temp->value)
                {
                    cout<<"Value already exists, Insert another value"<<endl;
                    return;
                }
                else if((new_node->value < temp->value) && (temp->left==NULL))
                {
                    temp->left=new_node;
                    cout<<"Value Inserted to the left"<<endl;
                    break;
                }
                else if(new_node->value< temp->value)
                {
                    temp=temp->left;
                }
                else if((new_node->value > temp->value) && (temp->right==NULL))
                {
                    temp->right=new_node;
                    cout<<"Value Inserted to the right"<<endl;
                    break;
                }
                else
                {
                    temp=temp->right;
                }

            }
        }
    }

    void printPreorder(TreeNode* r) //(Root,Left,Right)
    {
        if(r==NULL) return;
        //first print data of node
        cout<<r->value<<" ";
        //then recur on left subtree
        printPreorder(r->left);
        //now recur on right subtree
        printPreorder(r->right);
    }

    void printInorder(TreeNode* r) //(left,root,right)
    {
        if(r==NULL) return;
        //first recur on left child
        printInorder(r->left);
        //then print the data of node
        cout<<r->value<<" ";
        //now recur on right child
        printInorder(r->right);
    }

    void printPostorder(TreeNode* r) //(left,right,root)
    {
        if(r==NULL) return;
        //first recur on left subtree
        printPostorder(r->left);
        //then recur on right subtree
        printPostorder(r->right);
        //now deal with the node
        cout<<r->value<<" ";
    }

    void print2D(TreeNode *r, int space)
    {
        if(r==NULL) //base case
        {
            return;
        }
        space+=SPACE;   //increase distance between levels
        print2D(r->right,space);
        cout<<endl;
        for(int i=SPACE;i<space;i++)    //print current node after space count
        {
            cout<<" ";
        }
        cout<<r->value<<"\n";
        print2D(r->left,space); //process left child
    }

};

int main() {
    int option,val;
    BST obj;

    do
    {
       cout<<"What operation do you want to perform?"<<"Select Option number. Enter 0 to exit."<<endl;
       cout<<"1.Insert Node"<<endl; 
       cout<<"2.Search Node"<<endl; 
       cout<<"3.Delete Node"<<endl; 
       cout<<"4.Print BST values"<<endl; 
       cout<<"5.Clear Screen"<<endl; 
       cout<<"0.Exit Program"<<endl; 
       cin>>option;
       TreeNode *new_node=new TreeNode();

       switch(option)
       {
            case 0:
                break;
            case 1:
                cout<<"INSERT"<<endl;
                cout<<"Enter value of tree node to insert in BST:";
                cin>>val;
                new_node->value=val;
                obj.insertNode(new_node);
                cout<<endl;
                break;
            case 2:
                cout<<"SEARCH"<<endl;
                break;
            case 3:
                cout<<"DELETE"<<endl;
                break;
            case 4:
                cout<<"PRINTING AND TRAVERSING VALUES"<<endl;
                obj.print2D(obj.root,5);
                // obj.printPreorder(obj.root);
                // obj.printInorder(obj.root);
                obj.printPostorder(obj.root);
                break;
            case 5:
                // cout<<"CLR SCR"<<endl;
                system("cls");
                break;
            default:
                cout<<"Enter proper option number"<<endl;    
       }

    } while (option!=0);
    
    return 0 ;
}