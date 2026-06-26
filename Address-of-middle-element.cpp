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

    Node *slow = Head;
    Node *fast = Head;
    while (fast&&fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<endl;
    cout<<"The address of middle element of Linked List is: "<<slow<<endl;
    delete slow;
    delete fast;
    delete Head;
}
