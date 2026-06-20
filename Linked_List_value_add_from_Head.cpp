#include <iostream>
using std::cout,std::cin,std::string,std::endl;

struct  Node {
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    Node *Head = NULL;
    int number=0;
    cout<<"Enter the number of Boxes:"<<endl;
    cin>>number;

    for (int i=0;i<number;i++) {
        if (Head == NULL) {
            int input=0;
            cout<<"Enter value: "<<endl;
            cin>>input;
            Head = new Node(input);
        }
        else {
            int input=0;
            cout<<"Enter the value: "<<endl;
            cin>>input;
            Node *temp = new Node(input);
            temp->next = Head;
            Head = temp;
        }
    }
    Node *print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    delete Head;
}
