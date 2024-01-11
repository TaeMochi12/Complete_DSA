#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    Node *temp = node;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *addNode(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node *insertNode(Node *head, int data, int position)
{
    Node *newNode = new Node(data);
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Invalid position for insertion." << endl;
        }
    }
    return head;
}

Node *deleteNode(Node *head, int data)
{
    Node *temp = head;
    Node *prev = nullptr;

    // If the node to be deleted is the head
    if (temp != nullptr && temp->data == data)
    {
        head = temp->next;
        delete temp;
        return head;
    }

    // Search for the node to be deleted
    while (temp != nullptr && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the node is not present
    if (temp == nullptr)
    {
        cout << "Node with data " << data << " not found." << endl;
        return head;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp;
    return head;
}

bool search(Node *head, int d)
{
    if (head == NULL)
        return false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == d)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *ll = nullptr;

    int choice, data, position;
    bool ans;
    cout << "1. Add Node\n";
    cout << "2. Insert Node\n";
    cout << "3. Delete Node\n";
    cout << "4. Display\n";
    cout << "5. Search\n";
    cout << "0. Exit\n";
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data for the new node: ";
            cin >> data;
            ll = addNode(ll, data);
            cout << "Node added" << endl;
            break;
        case 2:
            cout << "Enter data for the new node: ";
            cin >> data;
            cout << "Enter position for insertion: ";
            cin >> position;
            ll = insertNode(ll, data, position);
            cout << "Node inserted" << endl;
            break;
        case 3:
            cout << "Enter data to delete: ";
            cin >> data;
            ll = deleteNode(ll, data);
            cout << "Node deleted" << endl;
            break;
        case 4:
            cout << "Linked List: ";
            display(ll);
            break;
        case 5:
            cout<<"Enter data to search:"<<endl;
            cin>>data;
            bool s=search(ll,data);
            cout<<"The data exists:"<<s<<endl;
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
