#include<iostream>
using std::cout,std::cin,std::endl;

struct Node {
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    Node *Head = nullptr;
    int n = 0;
    cout<<"Enter the number of boxes in linked lists:"<<endl;
    cin>>n;
    for (int i=0;i<n;i++) {
        if (Head == nullptr) {
            Head = new Node(i+1);
        }
        else {
            Node *temp = new Node(i+1);
            temp->next = Head;
            Head = temp;
        }
    }

    int a = 0;
    cout<<"Enter the number of times you want to rotate Linked List: "<<endl;
    cin>>a;
    for (int i=0;i<a;i++) {
        Node *print = Head;
        Node *prev = Head;
        while (print) {
            int data = print->data;
            print->data = prev->data;
            prev->data = data;
            print = print->next;
        }
    }
    while (Head) {
        cout<<Head->data<<" ";
        Head = Head->next;
    }
    delete Head;
}
