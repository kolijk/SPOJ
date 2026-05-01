#include <iostream>
#include <string>

int main() {
    
    int datasCount;
    std::cin >> datasCount;

    for (int x=0; x<datasCount; x++) {
        int length;
        std::cin >>length;
        std::cout <<length * length<<std::endl;
    }

    return 0;
}
