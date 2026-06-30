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
    int number = 0;
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
    cout<<"Enter the position you want to add value: "<<endl;
    cin>>position;
    if (position>-1 && position<length) {
        cout<<"Enter the number you want to add: "<<endl;
        cin>>number;
        if (position == 0) {
            Node *temp = new Node(number);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
        else {
            Node *curr = Head;
            while (--position) {
                curr = curr->next;
            }
            if (curr->next == nullptr) {
                Node *temp = new Node(number);
                temp->prev = Tail;
                Tail->next = temp;
                Tail = temp;
            }
            else {
                Node *temp = new Node(number);
                temp->prev = curr;
                temp->next = curr->next;
                curr->next = temp;
                curr->next->prev = temp;
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
