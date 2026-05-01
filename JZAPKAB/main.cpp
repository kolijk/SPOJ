#include <iostream>
#include <string>

int calc(std::string txt) {
    int result = 0;
    
    for (int x=0; x<txt.size(); x++) {
        if (txt[x] >= 'a' && txt[x] <= 'j') { 
            result += (txt[x] - 96); }
        if (txt[x] >= 'k' && txt[x] <= 's') {
            result += (txt[x] - 106) * 10; }
        if (txt[x] >= 'x' && txt[x] <= 'z') {
            result += (txt[x] - 117) * 100; }
        if (txt[x] == 't') {
            result += 100;
        }
        if (txt[x] == 'v') {
            result += 200;
        }
    }

    return result;
}

int main() {
    
    std::string txt;
    std::cin >> txt;//Get data

    std::cout <<calc(txt)<<std::endl;//Calc and display result

    return 0;
}
