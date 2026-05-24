#include <iostream>
#include <string>
#include <vector>

int calculate(std::string data) {
    int bufor = 0;
    std::string bufor2 = "";

    if (data[0] == '-') {//If first sign is minus
        bufor2 = data[0]; bufor2 += data[1];//Connect first and second sign together
        bufor = std::stoi(bufor2);//Convert connected signs to int variable
    }else {
        bufor = data[0] - 48;//Add first number to variable
    }

    int start = 1;
    if (bufor2.size() > 0) { start = 2; }
    for (int x = start; x<data.size(); x+=2) {//Start from second or third position
        if (data[x] == '+') {//If sign is add sign
            bufor += data[x + 1] - 48;//convert and sum number
        }else {//If sign is minus sign
            bufor -= data[x + 1] - 48;//convert and sub number
        }
    }

    return bufor;
}

int main() {

   int ilosc_danych;
   std::cin >> ilosc_danych;
   std::cin.ignore();

   std::string data;
   for (int x=0; x<ilosc_danych; x++) {
        std::getline(std::cin, data);//Get data
        std::cout << calculate(data) << std::endl;//Calc and display result
   }

    return 0;
}
