#include <iostream>
using std::cout,std::cin,std::string,std::endl;

struct  Node {
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    Node *Head = nullptr;
    for (int i=0;i<3;i++) {
        if (Head == nullptr) {
            Head = new Node(i+1);
        }else {
            Node *temp = new Node(i+1);
            temp->next = Head;
            Head = temp;
        }
    }

    Node *curr = Head;
    Node *pre = nullptr;
    while (curr->next != nullptr) {
        pre = curr;
        curr = curr->next;
    }
    delete curr;
    pre->next = nullptr;
    Node *print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    delete pre;
    delete Head;
}
