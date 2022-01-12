#include <bits/stdc++.h>
using namespace std;
class CircularList;
class Node
{
    int data;

public:
    Node *next;
    Node(int d) : data(d), next(NULL) {}

    int getData()
    {
        return data;
    }
    friend class CircularList;
};
class CircularList
{
    Node *head;
    Node *tail;

public:
    CircularList() : head(NULL), tail(NULL) {}

    Node *begin()
    {
        return head;
    }

    void push_front(int data)
    {
        Node *ptr = new Node(data);
        if (head == NULL)
        {
            ptr->data = data;
            ptr->next = ptr;
            head = ptr;
        }
        ptr->data = data;
        Node *p = head->next;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }

    void push_back(int data)
    {
        Node *ptr = new Node(data);
        if (head == NULL)
        {
            ptr->data = data;
            ptr->next = ptr;
            head = ptr;

        }
        ptr->data = data;
        Node *p = head->next;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout<<"List is empty!!!\n"<<endl;
        }
        else if (head->next == head)
        {
            cout<<"Deleted item is "<< head->data;
            head = NULL;
            free(head);
        }
        else
        {
            Node *p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            cout<<"Deleted item is "<< head->data;
            p->next = head->next;

            free(head);
            head = p->next;
        }
    }
    void pop_back()
    {
        Node *ptr, *p;
        if (head == NULL)
        {
            cout<<"List is empty!!!\n"<<endl;
        }
        else if (head->next == head)
        {
            cout<<"Deleted item is "<< head->data;
            head = NULL;
            free(head);
        }
        else
        {
            ptr = head;
            while (ptr->next != head)
            {
                p = ptr;
                ptr = ptr->next;
            }
            p->next = ptr->next;
            cout<<"Deleted item is "<<ptr->data;
            free(ptr);
        }
    }
    void traversal()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    CircularList cl;
    int choice;
    int info;
    int pos;
    int key;
    do
    {
        cout << "1.Push Back 2.Push Front 3.Pop Back 4.Pop Front 5.Traversal 6.Exit" << endl;
        cout << "Enter the choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Input: " << endl;
            cin >> info;
            cl.push_back(info);
            break;
        case 2:
            cout << "Input: " << endl;
            cin >> info;
            cl.push_front(info);
            break;
        case 3:
            cout << "popped back" << endl;
            cl.pop_back();
            break;
        case 4:
            cout << "popped front" << endl;
            cl.pop_front();
            break;
        case 5:
            cout << "The nodes are: " << endl;
            cl.traversal();
            cout << endl;
            break;
        default:
            cout << "Thank You!" << endl;
        }
    } while (choice != 6);
    cout << endl;
    return 0;
}