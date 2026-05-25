#include <iostream>
#include <string>
#include <vector>

//Convert binary to decimilian
int convertBintoDec(std::string data) {
    int bufor = 0;
    int pos = 1;
    for (int x=data.size()-1; x>=0; x--) {
        if (data[x] == '1') {
            bufor += pos;
        }
        pos *= 2;
    }
    return bufor;
}

//Function getting all next 5 numbers adding together and converting for number decimilian
std::vector <int> resultCalc(std::string binary) {
    std::vector <int> bufor;

    for (int x=0; x<binary.size();) {
        std::string bufor2 = "";
        bufor2 += binary[x];
        bufor2 += binary[x + 1];
        bufor2 += binary[x + 2];
        bufor2 += binary[x + 3];
        bufor2 += binary[x + 4];
        bufor.push_back(convertBintoDec(bufor2));
        x += 5;
    }

    return bufor;
}

//Function who convert content of vector from int to letters
std::string convertVecIntToString(std::vector <int> data) {
    std::string result = "";
    
    for (int x=0; x<data.size(); x++) {
        result += 'A' + data[x];
    }
    
    return result;
}

int main() {

   int N = 0;
   std::cin >>N;
   std::cin.ignore();

   for (int x=0; x<N; x++) {
        std::string bufor;
        std::cin >>bufor;
        std::cout << convertVecIntToString(resultCalc(bufor))<<std::endl;
   } 

    return 0;
}
