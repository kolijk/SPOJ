#include <iostream>
#include <string>
#include <vector>

int main() {

    int howMuch;
    std::vector <int> numbers;

    std::cin >>howMuch;//Get how much numbers will be
    std::cin.ignore();

    int bufor;
    for (int x=0; x<howMuch; x++) {
        std::cin >>bufor;//get all the numbers
        numbers.push_back(bufor);
    }

    int counter = 0;
    for (int x=2; x< howMuch; x++) {
        //Check number third is equal summ number second + number first 
        if (numbers[x] == numbers[x-1] + numbers[x-2]) {
            counter++;
        }
    }

    std::cout <<counter<<std::endl;//Display result
    
    return 0;
}
