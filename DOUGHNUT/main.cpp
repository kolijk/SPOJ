#include <iostream>
#include <string>

//5 15  3
std::string test(int c, int k, int w) {

    if (c * w <= k) {
        return "yes";
    }

    return "no";
}

int main() {
   
    int t;//Tests number
    int c, k, w;//Data for the test
    //c - liczba kotow
    //k - Udzwig Harrego
    //w - waga paczka

    std::cin>>t;
    std::cin.ignore();

    for (int x=0; x<t; x++) {
        std::cin >>c>>k>>w;
        std::cout <<test(c, k, w)<<std::endl;
        std::cin.ignore();
    }

    return 0;
}
