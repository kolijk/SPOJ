#include <iostream>
#include <vector>
#include <string>

int main() {
   
    std::vector <long int> numbers;
    int n, x;
    char c;
    std::cin >>n;
    std::cin.ignore();

    for (int x=0; x<n; x++) {
        long int buf;
        std::cin >> buf;
        numbers.push_back(buf);
        std::cin.ignore();
    }

    std::cin>>c>>x;

    if (c == '<') {
        for (int y=0; y<numbers.size(); y++) {
            if (numbers[y] < x) {
                std::cout <<numbers[y]<<std::endl;
            }
        }
    }else {
        for (int y = 0; y < numbers.size(); y++) {
            if (numbers[y] > x) {
                std::cout << numbers[y] << std::endl;
            }
        }
    }



    return 0;
}
