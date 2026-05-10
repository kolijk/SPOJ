#include <iostream>
#include <string>
#include <vector>

std::string prepare(std::string txt) {
    std::string buf;
    
    for (int x=0; x<txt.size(); x++) {
        char c = txt[x] - 63;
        if (c >= 2 && c <= 4) { buf += '2'; }
        if (c >= 5 && c <= 7) { buf += '3'; }
        if (c >= 8 && c <= 10) { buf += '4'; }
        if (c >= 11 && c <= 13) { buf += '5'; }
        if (c >= 14 && c <= 16) { buf += '6'; }
        if (c >= 17 && c <= 20) { buf += '7'; }
        if (c >= 21 && c <= 23) { buf += '8'; }
        if (c >= 24 && c <= 27) { buf += '9'; }
    }

    return buf;
}

int main() {
   
    std::string txt;
    std::vector <std::string> data; 
    int how;

    std::cin >> how;
    std::cin.ignore();

    for (int x=0; x<how; x++) {
        std::getline(std::cin, txt);
        std::cout << prepare(txt) << std::endl;
    }

    return 0;
}
