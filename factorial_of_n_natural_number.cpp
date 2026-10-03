#include <iostream>

int fact(int num) {
    if (num == 0) {
        return 1;
    }
    return num * fact(num-1);
}

int main() {
    std::cout<<fact(3);
}

