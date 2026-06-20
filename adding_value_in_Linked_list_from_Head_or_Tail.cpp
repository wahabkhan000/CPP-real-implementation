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
    Node *Tail = NULL;
    int number=0;
    cout<<"Enter the number of Boxes:"<<endl;
    cin>>number;

    for (int i=0;i<number;i++) {
        if (Head == NULL) {
            int input=0;
            cout<<"Enter value: "<<endl;
            cin>>input;
            Head = new Node(input);
            Tail = Head;
        }
        else {
            int input=0;
            cout<<"Enter the value: "<<endl;
            cin>>input;
            Tail->next= new Node(input);
            Tail = Tail->next;
        }
    }
    Node *print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    cout<<endl;
    bool flag;
    cout<<"Enter '0' if you want to add from Head in Linked List "
          "and Enter '1' if you want to add from Tail in Linked List:"<<endl;
    cin>>flag;
    if (flag==false) {
        int input=0;
        cout<<"Enter the number of values you want to add:"<<endl;
        cin>>input;
        for (int i=0;i<input;i++) {
            int value=0;
            cout<<"Enter value:"<<endl;
            cin>>value;
            Node *temp = new Node(value);
            temp->next = Head;
            Head = temp;
        }
    }
    else {
        int input=0;
        cout<<"Enter value:"<<endl;
        cin>>input;
        for (int i=0;i<input;i++) {
            int value=0;
            cout<<"Enter value:"<<endl;
            cin>>value;
            Tail->next = new Node(value);
            Tail = Tail->next;
        }
    }

    print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }

    delete Head;
}
