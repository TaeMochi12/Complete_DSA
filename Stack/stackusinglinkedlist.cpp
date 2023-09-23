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
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    bool checkIfNodeExists(Node *n)
    {
        Node *temp = top;
        bool exist = false;
        while (temp != NULL)
        {
            if (temp->key == n->key)
            {
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    void push(Node *n)
    {
        if (top == NULL)
        {
            top = n;
            cout << "Node PUSHED" << endl;
        }
        else if (checkIfNodeExists(n))
            cout << "Same key not allowed" << endl;
        else
        {
            Node *temp = top;
            top = n;
            n->next = temp; // jo phle top tha uska address next mein daal do new top k
            cout << "Node PUSHED" << endl;
        }
    }
    Node *pop()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return temp;
        }
        else
        {
            temp = top;
            top = top->next;
            return temp;
        }
    }
    Node *peek()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
        }
        else
            return top;
    }

    // void change(Node* n,int value)
    // {
    //     if(checkIfNodeExists(n))
    //     {
    //         n->data=value;
    //         cout<<"Value changed at node with key:"<<n->key<<endl;
    //     }
    //     else
    //     {
    //         cout<<"No node exists with key value:"<<n->key<<endl;
    //     }
    // }

    int count()
    {
        int count = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display()
    {
        Node *temp = top;
        if (top == NULL)
            cout << "Stack is empty" << endl;
        else
        {
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")" << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack s1;

    int option, key, data, value;
    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.isEmpty()" << endl;
        cout << "4.peek()" << endl;
        cout << "5.count()" << endl;
        cout << "6.display()" << endl;
        cout << "7.Clear Screen" << endl;

        cin >> option;
        Node *new_node = new Node();
        switch (option)
        {
        case 1:
            cout << "Enter key and value of node to push:" << endl;
            cin >> key;
            cin >> data;
            new_node->key = key;
            new_node->data = data;
            s1.push(new_node);
            break;
        case 2:
            new_node = s1.pop();
            cout << "Popped Node:"
                 << "(" << new_node->key << "," << new_node->data
                 << ")" << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
            break;
        case 4:
            cout << "Peek function called:" << endl;
            new_node = s1.peek();
            cout << "Top of stack:"
                 << "(" << new_node->key << "," << new_node->data
                 << ")" << endl;
            break;
        case 5:
            cout << "Count Function called-Number if items in the stack are:" << s1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called-" << endl;
            s1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number" << endl;
        }
    } while (option != 0);

    return 0;
}