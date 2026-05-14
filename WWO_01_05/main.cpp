#include <iostream>
#include <string>

int calcBinary(std::string binary) {
    int bufor = 0;
    int powCount = 1;
    for (int x=binary.size()-1; x>=0; x--) {
        if (binary[x] == '1') {
            bufor += powCount;
        }
        powCount *= 2;
    }

    return bufor;
}

std::string prepare(int a, int b, int c, int d) {
    
    int hour10 = calcBinary(std::to_string(a));
    int hour1 = calcBinary(std::to_string(b));

    int min10 = calcBinary(std::to_string(c));
    int min1 = calcBinary(std::to_string(d));

    return std::to_string(hour10) + std::to_string(hour1) + ":" + std::to_string(min10) + std::to_string(min1);

}

int main() {
   
    int a, b, c, d;

    std::cin >>a>>b>>c>>d;

    std::cout <<prepare(a, b, c, d)<<std::endl;

    return 0;
}
