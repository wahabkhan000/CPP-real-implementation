#include <iostream>

int sumSquare(int num) {
    if (num == 0) {
        return 0;
    }
    return   ( num * num + sumSquare(num-1));
}

int main() {
    std::cout<<sumSquare(4);
}

