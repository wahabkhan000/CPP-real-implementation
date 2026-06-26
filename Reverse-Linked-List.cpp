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
    int arr[n];
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

    Node *print = Head;
    cout<<"Original values are: ";
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    cout<<endl;
    print = Head;
    int i=0;
    while (print) {
        arr[i] = print->data;
        print = print->next;
        i++;
    }
    i--;
    cout<<"Reversed values are: ";
    print = Head;
    while (print) {
        print->data = arr[i];
        print = print->next;
        i--;
    }
    print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }

    delete print;
    delete Head;
}
