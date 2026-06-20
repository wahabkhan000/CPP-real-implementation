#include <iostream>
using std::cout,std::cin,std::string,std::endl;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    Node *Head = NULL;
    int n;
    cout<<"Enter Value:"<<endl;cin>>n;
    for (int i=0;i<n;i++) {
        if (Head == NULL) {
            int a;
            cout<<"Enter value:"<<endl;cin>>a;
            Head = new Node(a);
        }
        else {
            Node *Tail = Head;
            while (Tail->next != NULL) {
                Tail = Tail->next;
            }
            int a;
            cout<<"Enter value:"<<endl;cin>>a;
            Tail->next = new Node(a);
        }
    }
    Node *Next = Head;
    while (Next) {
        cout<<Next->data<<" ";
        Next = Next->next;
    }

    cout<<Head->data<<endl;
    delete Head;
}
