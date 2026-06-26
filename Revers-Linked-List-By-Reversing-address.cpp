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
    Node *prev = nullptr;
    Node *next = nullptr;
    while (pres) {
        next = pres->next;
        pres->next = prev;
        prev  = pres;
        pres = next;
    }
    Head = prev;
    while (prev) {
        cout<<prev->data<<" ";
        prev = prev->next;
    }

    delete pres;
    delete prev;
    delete next;
    delete Head;
}
