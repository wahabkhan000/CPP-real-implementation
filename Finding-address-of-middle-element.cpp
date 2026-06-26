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

    Node *pres = Head;
    int count = 0;
    while (pres) {
        count++;
        pres = pres->next;
    }
    pres = Head;
    count/=2;
    while (count--) {
        pres = pres->next;
    }
    cout<<"The address of middle box of Linked List is: "<<pres<<endl;

    delete pres;
    delete Head;
}
