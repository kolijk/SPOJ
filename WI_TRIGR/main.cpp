#include <iostream>
#include <vector>
#include <string>

std::string arr1[9] = {"??=", "??/", "??'", "??(", "??)","??!", "??<", "??>", "??-"};
std::string arr2[9] = {"#", "\\", "^", "[", "]","|", "{", "}", "~'"};

std::string check(char thirdSign) {

    for (int x = 0; x < 9; x++) {
        if (thirdSign == arr1[x][2]) {
            return arr2[x];
        }
    }

    return "NULL";

}

std::vector <std::string> prepareCode(std::vector <std::string> code) {

    std::string bufor;

    for (int y = 0; y < code.size(); y++) {
        for (int x = 0; x < code[y].size(); x++) {
            if (code[y][x] != '?') {
                bufor += code[y][x];
            }
            else {
                if (x + 2 < code[y].size()) {
                    std::string result = check(code[y][x + 2]);
                    if (result != "NULL") {
                        bufor += result;
                        x += 2;
                    }
                    else {
                        bufor += code[y][x];
                    }
                }
                else {
                    bufor += code[y][x];
                }
            }
        }
        code[y] = bufor;
        bufor.clear();
        bufor.begin();
    }

    return code;
}

void displayCode(std::vector <std::string> preparedCode) {
    
    for (int x = 0; x < preparedCode.size(); x++) {
        std::cout <<preparedCode[x]<<std::endl;
    }

}

int main() {
    
    std::string bufor;
    std::vector <std::string> data;

    while (std::getline(std::cin, bufor)) {
        data.push_back(bufor);
        bufor.clear();
        bufor.begin();
    }
    
    displayCode(prepareCode(data));

    return 0;

}
