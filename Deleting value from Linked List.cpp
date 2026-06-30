#include <iostream>
using std::cout,std::cin,std::endl;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    Node *Head = nullptr;
    Node *Tail = Head;
    int position  = 0;
    int length = 0;
    cout<<"Enter the length of linked list: "<<endl;
    cin>>length;
    for (int i=0;i<length;i++) {
        if (Head == nullptr) {
            Head = new Node(i+1);
            Tail = Head;
        }
        else {
            Node *temp =new Node(i+1);
            Tail->next = temp;
            temp->prev = Tail;
            Tail = temp;
        }
    }

    Node *print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    cout<<endl;
    cout<<"Enter the position you want to delete: "<<endl;
    cin>>position;
    if (position>0 && position<=length) {
        if (position == 1) {
            Node *temp = Head;
            Head = temp->next;
            delete temp;
        }
        else {
            Node *curr = Head;
            if (position == length) {
                Node *temp = Tail;
                Tail->prev->next = nullptr;
                Tail = Tail->prev;
                delete temp;
            }
            else {
                while (--position) {
                    curr = curr->next;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
            }
        }

        cout<<endl;
        print = Head;
        while (print) {
            cout<<print->data<<" ";
            print = print->next;
        }
        delete print;
    }
    else {
        cout<<"You are accessing unauthorized address."<<endl;
    }

    delete Tail;
    delete Head;
}
