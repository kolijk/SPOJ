#include <iostream>
#include <string>

//Function generate string result
std::string generate(int a, int b) {
    std::string bufor;

    for (int x=a; x<=b; x++) {
        if (x % 6 == 0) {
            bufor += "ab";
        }
        if (x % 2 == 0 && x % 3 != 0) {
            bufor += "a";
        }
        if (x % 3 == 0 && x % 2 != 0) {
            bufor += "b";
        }
    }

    return bufor;
}

int main() {

    int a, b;
    std::cin>>a>>b;//Get data

    std::cout <<generate(a, b)<<std::endl;//Display result

    return 0;

}
