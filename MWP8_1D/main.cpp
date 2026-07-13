#include <iostream>
#include <string>

struct Data {
    std::string one;
    std::string two;
    std::string three;
};

// Szybka konwersja Hex na Dec bez użycia wolnej funkcji pow()
int convertHexDec(const std::string& HEX) {
    int result = 0;
    for (char c : HEX) {
        int number;
        if (c >= 'A' && c <= 'F') {
            number = c - 'A' + 10;
        }
        else {
            number = c - '0';
        }
        result = result * 16 + number;
    }
    return result;
}

Data getHex(const std::string& data, int index) {
    Data dataRet;//Get
    dataRet.one = data.substr(index + 1, 2);
    dataRet.two = data.substr(index + 3, 2);
    dataRet.three = data.substr(index + 5, 2);
    return dataRet;
}

std::string decode(const std::string& data) {
    if (data.empty()) return "";
    std::string result;

    
    for (int x = 0; x + 6 < data.size(); x += 7) {
        if (data[x] == '#') {
            Data HEX = getHex(data, x);//Get 3 hex numbers
            result += char(convertHexDec(HEX.one) + convertHexDec(HEX.two) + convertHexDec(HEX.three));//Summ 3 numbers from hex to dec
        }
    }
    return result;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string data;//Get data
    if (std::cin >> data) {
        std::cout << decode(data);//Decode and display decoded text
    }

    return 0;
}
