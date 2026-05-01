#include <iostream>
#include <string>

enum TYPE{
    D = 0,
    G = 1
};

void decodeDisplay(std::string data) {
    std::string prepared;

    for (int x=4; x<data.size(); x++) {
        if (data[x - 1] == 'D' && data[x] == 'G') {
            prepared += '1'; }
        if (data[x - 1] == 'G' && data[x] == 'G') { 
            prepared += '0'; }
        if (data[x - 1] == 'D' && data[x] == 'D') { 
            prepared += '0'; }
        if (data[x - 1] == 'G' && data[x] == 'D') {
            prepared += '1';
        }
    }

    std::cout << prepared << std::endl;//Display result
}

void codeDisplay(std::string data) {
    std::string prepared;

    prepared = "DDDD";
    int i = 3;//index

    for (int x=0; x<data.size(); x++) {
        if (data[x] == '0' && prepared[x + i] == 'D') {
            prepared += 'D'; }
        if (data[x] == '0' && prepared[x + i] == 'G') {
            prepared += 'G'; }

        if (data[x] == '1' && prepared[x + i] == 'D') {
            prepared += 'G'; }
        if (data[x] == '1' && prepared[x + i] == 'G') {
            prepared += 'D'; }
    }

    std::cout << prepared <<std::endl;//Display result
}

int main() {
    
    std::string txt;
    std::getline(std::cin, txt);//Input stream for data

    if (txt[0] == '1' || txt[0] == '0') { codeDisplay(txt); }//When we will code data
    if (txt[0] == 'G' || txt[0] == 'D') { decodeDisplay(txt); }//When we will decode data

    return 0;
}
