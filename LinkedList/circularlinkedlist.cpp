#include<iostream>
using namespace std ;

class Node{
    public:
        int key;
        int data;
        Node* next;

        Node()
        {
            key=0;
            data=0;
            next=NULL;
        }
        Node(int k,int d)
        {
            key=k;
            data=d;
        }
};

class CircularLinkedList
{
    public:
        Node* head;

        CircularLinkedList()
        {
            head=NULL;
        }

        // 1. Check if node exists
        Node* nodeExists(int k)
        {
            Node* temp=NULL;
            Node* ptr=head;

            if(ptr==NULL)
            {
                return temp;
            }
            else
            {
                do
                {
                    if(ptr->key==k)
                    {
                        temp=ptr;
                    }
                    ptr=ptr->next;
                } while (ptr!=head);
                return temp;
            }
            //return temp;
        }

        // 2. Append a node to the list
        void appendNode(Node *new_node)
        {
            if(nodeExists(new_node->key)!=NULL)
            {
                cout<<"Node already exists with key value:"<<new_node->key<<".Append another node with different key value"<<endl;
            }
            else
            {
                if(head==NULL)
                {
                    head=new_node;
                    new_node->next=head;   //it will point to itself
                    cout<<"Node prepended at first head position"<<endl;
                }
                else
                {
                    if(head==NULL)
                    {
                    head=new_node;
                    new_node->next=head;   //it will point to itself
                    cout<<"Node appended at first head position"<<endl;
                    }
                    else
                    {
                        Node* ptr=head;
                    while(ptr->next!=head)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=new_node;
                    new_node->next=head;  
                    cout<<"Node Appended"<<endl;
                    }
                    
                }
            }
        }

        // 3. Prepend Node-Attach a node at the start
        void prependNode(Node* new_node)
        {
            if(nodeExists(new_node->key)!=NULL)
            {
                cout<<"Node already exists with key value:"<<new_node->key<<".Prepend node with different key value"<<endl;
            }
            else
            {
                Node* ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=new_node;  //the last node will point to prepended node
                new_node->next=head;  //the prepended node will point next to current head 
                head=new_node;  //make the prepended node head
                cout<<"Node prepended"<<endl;
            }
        }

        // 4. Insert a node after a particular node in the list
        void insertNodeAfter(int k,Node* new_node)
        {
            Node* ptr=nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value of:"<<k<<endl;
            }
            else
            {
                if(nodeExists(new_node->key)!=NULL)
                {
                    cout<<"Node already exists with key value:"<<new_node->key<<".Insert another node with different key value"<<endl;
                }
                else
                {
                    if(ptr->next==head)
                    {
                        new_node->next=head;
                        ptr->next=new_node;
                        cout<<"Node inserted at the end"<<endl;
                    }
                    else
                    {
                        new_node->next=ptr->next;
                        ptr->next=new_node;
                        cout<<"Node inserted in between"<<endl;
                    }
                }
            }
        }

        // 5. Delete node by unique key
        void deleteNodeByKey(int k)
        {
            Node* ptr=nodeExists(k);
            if(ptr==NULL)
            {
                cout<<"No node exists with key value of:"<<k<<endl;
            }
            else
            {
                if(ptr==head)
                {
                    if(head->next==head)  //only one node is present
                    {
                        head=NULL;
                        cout<<"Head node unlinked..list empty"<<endl;
                    }
                    else
                    {
                        Node* ptr1=head;
                        while(ptr1->next!=head)
                        {
                            ptr1=ptr1->next;
                        }
                        ptr1->next=head->next;
                        head=head->next;
                        cout<<"Node unlinked with key value:"<<k<<endl;
                    }
                }
                else
                {
                    Node*  temp=NULL;
                    Node* prevptr=head;
                    Node* currentptr=head->next;
                    while(currentptr!=NULL)  //starting the loop from the position next to head, as ptr!=head here
                    {
                        if(currentptr->key==k)
                        {
                            temp=currentptr;
                            currentptr=NULL;  //this will work ass break
                        }
                        else
                        {
                            prevptr=prevptr->next;
                            currentptr=currentptr->next;
                        }
                    }
                    prevptr->next=temp->next;
                    cout<<"Node unlinked with key value:"<<k<<endl;
                }
            }
        }

        // 6. Update node
        void updateNodeByKey(int k,int new_data)
        {
            Node* ptr=nodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data=new_data;
                cout<<"Node data updated successfully"<<endl;
            }
            else
            {
                cout<<"Node doesn't exist with key value:"<<k<<endl;
            }
        }

        // 7. Printing
        void printList()
        {
            if(head==NULL)
            {
                cout<<"No nodes in list"<<endl;
            }
            else
            {
                cout<<endl<<"Head address:"<<head<<endl;
                cout<<"Linked List values:"<<endl;
                Node* temp=head;
                do
                {
                    /* code */
                    cout<<"("<<temp->key<<","<<temp->data<<","<<temp->next<<")-->";
                    temp=temp->next;
                } while (/* condition */temp!=head);
                cout<<endl;
                
            }
        }

};

int main() {
    CircularLinkedList obj;
    int option;
    int key1,k1,data1;
    do
    {
        cout<<endl<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. appendNode()"<<endl;
        cout<<"2. prependNode()"<<endl;
        cout<<"3. insertNodeAfter()"<<endl;
        cout<<"4. deleteNodeByKey()"<<endl;
        cout<<"5. updateNodeByKey()"<<endl;
        cout<<"6. print()"<<endl;
        cout<<"7. Clear Screen"<<endl<<endl;

        cin>>option;
        Node* n1=new Node();

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Append Node Operation\nEnter key and data of the node to be appended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.appendNode(n1);
                break;
            case 2:
                cout<<"Prepend Node Operation\nEnter key & data of the node to be prepended"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;
                obj.prependNode(n1);
                break;
            case 3:
                cout<<"Insert Node After Operation\nEnter key of existing Node after which you want to insert this new node:"<<endl;
                cin>>k1;
                cout<<"Enter key and data to the new node first:"<<endl;
                cin>>key1;
                cin>>data1;
                n1->key=key1;
                n1->data=data1;

                obj.insertNodeAfter(k1,n1);
                break;
            case 4:
                cout<<"Delete Node by key operation\nEnter key of the node to be deleted:"<<endl;
                cin>>k1;
                obj.deleteNodeByKey(k1);
                break;
            case 5:
                cout<<"Update Node by key operation\nEnter key and new data to be updated:"<<endl;
                cin>>key1;
                cin>>data1;
                obj.updateNodeByKey(key1,data1);
                break;
            case 6:
                obj.printList();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout<<"Enter proper option number"<<endl;

        }

    } while (option!=0);
    
    return 0 ;
}