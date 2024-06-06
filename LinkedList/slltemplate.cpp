#include<iostream>
using namespace std ;

class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int val)
    {
        this->val=val;
        next=nullptr;
    }
};

void display(ListNode* head)
{
    ListNode *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}

int length(ListNode* head)
{
    ListNode *temp=head;
    int l=0;
    while(temp!=nullptr)
    {
        l++;
    }
    return l;
}

ListNode* reverse(ListNode *head)
{
    ListNode* current=head,*temp=head,*prev=nullptr;
    while(current!=nullptr)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    return prev;
}

ListNode* insert(ListNode* head,ListNode *node,int k)
{
    if(head==nullptr) head=node;
    else{
        if(k==0) 
        {
            node->next=head;
            head=node;
        }
        else if(k==length(head)-1)
        {
            ListNode* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=node;
            node->next=nullptr;
        }
        else{
            ListNode* temp=head;
            int p=0;
            while(p<k-1)
            {
                temp=temp->next;
            }
            node->next=temp->next;
            temp->next=node;
        }
    }
    return head;
}

ListNode* del(ListNode* head,int k)
{
    if(head==nullptr) return head; 
    else if(head->next==nullptr) head=nullptr;
    else{
        if(k==0)
        {
            ListNode* temp=head;
            head=head->next;
            free(temp);
        }
        else if(k==length(head)-1)
        {
            ListNode* temp=head;
            while(temp->next->next!=nullptr)
            {
                temp=temp->next;
            }
            ListNode* delt=temp->next;
            temp->next=nullptr;
            free(delt);
        }
        else
        {
          ListNode* temp=head;
            int p=0;
            while(p<k-1)
            {
                temp=temp->next;
            }  
            ListNode* delt=temp->next;
            temp->next=temp->next->next;
            free(delt);
        }
    }
    return head;
}

int main() {
    ListNode *head=new ListNode(10);
    head->next=new ListNode(20);
    head->next->next=new ListNode(30);
    head->next->next->next=new ListNode(40);
    display(head);
    ListNode* newhead=reverse(head);
    display(newhead);
    return 0 ;
}