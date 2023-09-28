#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    // Check if node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // Append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ".Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended" << endl;
            }
        }
    }

    // 3. Prepend Node - Attach a node at the start
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ".Prepend another node with different key value" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
    }

    // 4.Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k); // here we have to store the pointer whose key value is k as we have to insert node n after node with k as key value
        if (ptr == NULL)
        {
            cout << "No node exists with key value:" << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL) // the node which we have to insert should not be already present
            {
                cout << "Node already exists with key value: " << n->key << ".Insert another node with different key value" << endl;
            }
            else // insertion
            {
                // the order of below statements should be exactly the same
                n->next = ptr->next; // jo ptr ka next tha wo ab n k next hoga
                ptr->next = n;       // ptr k next ab n hoga
                cout << "Node Inserted" << endl;
            }
        }
    }

    // 5.Delete node by unique key
    void deleteNodeByKey(int k) // Here the node will not be deleted from the memory but will get just unlimked from the linked list
    {
        if (head == NULL)
        {
            cout << "Singly Linked List already empty, can't delete anything" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k) // if we wish to delete the first node itself
            {
                head = head->next; // address of the second node stored in head
                cout << "Node unlinked with key value:" << k << endl;
            }

            else // to delete a node which is present somewhere in between or end
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next; // it will store the node which we have to delete
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr; // when we get the match, we store its address in temp node
                        currentptr = NULL; // to stop the while loop once the match is found
                    }
                    else
                    { // moving to the next nodes for traversing
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next; // previous node k next mein temp node k next wale ko store kr diya jisse temp yani jo delete krna tha wo beech se hat k unlink ho jaye
                    cout << "Node unlinked with key value:" << k << endl;
                }
                else
                {
                    cout << "Node doesn't exist with key value:" << k << endl;
                }
            }
        }
    }

    // 6.Update node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "Node doesn't exist with key value:" << k << endl;
        }
    }

    // Printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in singly linked list" << endl;
        }
        else
        {
            cout << endl
                 << "Singly Linked List Values: ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")--> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};

int main()
{

    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    
        cout << "1.appendNode()" << endl;
        cout << "2.prependNode()" << endl;
        cout << "3.insertNodeAfter()" << endl;
        cout << "4.deleteNodeByKey()" << endl;
        cout << "5.updateNodeByKey()" << endl;
        cout << "6.print()" << endl;
        cout << "7.nodeExists()" << endl;
        cout << "8.Clear Screen" << endl;

    do
    {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        
        cin >> option;
        Node *n1 = new Node(); // DOUBTTTTTTTTTTTTTTTT
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation\nEnter key and data of the Node to be appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node Operation\nEnter key and data of the Node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node Operation\nEnter key of existing Node after which you want to Insert this New node:" << endl;
            cin >> k1;
            cout << "Enter key and data of the new node first:" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete Node by key operation- \nEnter key of the node to be deleted:" << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update Node by key operation- \nEnter key and new data to be updated:" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printList();
            break;
        case 7:
            cout << "Enter the key of the node to be searched:" << endl;
            cin >> key1;
            n1 = s.nodeExists(key1);
            if (n1 == NULL)
                cout << "There is no node with the key value:" << key1 << endl;
            else
                cout << "The node with key value:" << key1 << " has data:" << n1->data << endl;
            break;
        case 8:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number" << endl;
        }
    } while (option != 0);
    return 0;
}