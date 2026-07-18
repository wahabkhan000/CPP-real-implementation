#include <iostream>
using std::cout, std::cin, std::string, std::endl;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

int main() {
    Node *Head = nullptr;
    Node *Tail = Head;
    int length = 0;

    cout << "Enter the length of linked list: " << endl;
    cin >> length;

    for (int i = 0; i < length; i++) {
        if (Head == nullptr) {
            int input = 0;
            cin >> input;
            Head = new Node(input);
            Tail = Head;
        }
        else {
            int input = 0;
            cin >> input;
            Node *temp = new Node(input);
            Tail->next = temp;
            temp->prev = Tail;
            Tail = temp;
        }
    }

    Tail->next = Head;
    Head->prev = Tail;

    Node *print = Head;
    int move = -1;

    while (move != 0) {
        int key = 0;

        do {
            if (key == 0) {
                cout << "If you want to move select from menu:" << endl;
                cout << "1) Move Forward [Press 1]\n"
                        "2) Move Backward [Press 2]\n"
                        "3) Stop Moving [Press 0]" << endl;
            }
            else {
                cout << "You pressed wrong button! Press Again." << endl;
                cout << "1) Move Forward [Press 1]\n"
                        "2) Move Backward [Press 2]\n"
                        "3) Stop Moving [Press 0]" << endl;
            }

            key = 1;
            cin >> move;

        } while (move != 0 && move != 1 && move != 2);

        if (move == 1) {
            cout << print->data << " ";
            print = print->next;
        }

        if (move == 2) {
            cout << print->data << " ";
            print = print->prev;
        }

        cout << endl;
    }

    cout << "You Press [0]. So you exit the program." << endl;

    Node *curr = Head->next;
    while (curr != Head) {
        Node *temp = curr->next;
        delete temp;
        curr = temp;
    }
    delete Head;
    Head = nullptr;
    return EXIT_SUCCESS;
}
