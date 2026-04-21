#include <iostream>

int calc(int num) {
    int count = 0;

    while (num > 1) {
        if (num %2 == 0) {//liczba parzysta
            num = num / 2;
        }else {
            num = 3 * num + 1;
        }
        count++;
    }

    return count;
}

int main() {
    
    int howManyTests;
   
    std::cin >> howManyTests;
    for (int x=0; x<howManyTests; x++) {
        int buf;
        std::cin >>buf;
        std::cout <<calc(buf)<<std::endl;
    }

    return 0;
}
