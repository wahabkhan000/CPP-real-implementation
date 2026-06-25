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
    int number = 0;
    cout<<"Enter the value of number: "<<endl;
    cin>>number;
    int delete_num = 0;
    cout<<"Enter the value of block you want to delete: "<<endl;
    cin>>delete_num;
    for (int i=0;i<number;i++) {
        if (Head == nullptr) {
            Head = new Node(i+1);
        }else {
            Node *temp = new Node(i+1);
            temp->next = Head;
            Head = temp;
        }
    }
    if (delete_num>0&&delete_num<=number) {
        if (delete_num == 1) {
            Node *curr = Head;
            Head = Head->next;
            delete curr;
        }
        else {
            Node *curr = Head;
            Node *pre = nullptr;
            delete_num--;
            while (delete_num--) {
                pre = curr;
                curr = curr->next;
            }
            pre->next = curr->next;
            delete curr;
        }
    }

    Node *print = Head;
    while (print) {
        cout<<print->data<<" ";
        print = print->next;
    }
    delete Head;
}
