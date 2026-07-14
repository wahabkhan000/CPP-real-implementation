#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using std::cout,std::cin,std::string,std::endl,std::vector,std::pair;

struct  Node {
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
pair<Node*,int> allocation(int length) {
    Node *Head = nullptr;
    vector<int>data;
    for (int i=0;i<length;i++) {
        if (Head == nullptr) {
            int n;cin>>n;
            Head = new Node(n);
        }else {
            int n;cin>>n;
            Node *temp = new Node(n);
            temp->next = Head;
            Head = temp;
        }
    }
    Node *traverse = Head;
    while (traverse) {
        data.push_back(traverse->data);
        traverse = traverse->next;
    }
    int  i = 0;
    Node *Traverse = Head;
    std::sort(data.begin(),data.end());
    while (Traverse) {
        Traverse->data = data[i];
        Traverse = Traverse->next;
        i++;
    }
    delete traverse;
    return {Head,i};
}
Node *removing(Node *Head,int length) {
    if (length>1) {
        Node *prev = Head;
        Node *traverse = Head->next;
        while (traverse) {
            if (prev->data == traverse->data) {
                Node *temp = traverse;
                traverse = traverse->next;
                prev->next = traverse;
                delete temp;
            }
            else {
                prev = traverse;
                traverse = traverse->next;
            }
        }
        return Head;
    }
    else {
        delete Head;
        return nullptr;
    }
}
int main() {
    int length = 0;
    cout<<"Enter the length of first number: "<<endl;
    cin>>length;
    pair<Node*,int>ans = allocation(length);
    Node *Head = removing(ans.first,ans.second);
    if (Head) {
        Node *print = Head;
        while (print) {
            cout<<print->data<<" ";
            print = print->next;
        }
        delete print;
    }
    else {
        cout<<"Value deleted.";
    }
    delete Head;
}
