#include <iostream>
#include <string>


std::string szyfruj(std::string txt, std::string key) {
    std::string bufor;
    int indexKey = 0;
    //(0-25) (A-Z)

    for (int t = 0; t < txt.size(); t++) {
        int b = txt[t] - 65;
        int c = key[indexKey] - 48;//c definiuje o ile przesunac w prawo

        int docelowoA;
        int docelowoB;//Ktora z kolei zabrac litere
        if (b + c > 25) {
            docelowoA = (b + c) / 25;
            docelowoB = (b + c) - (docelowoA * 25);
            bufor += (docelowoB + 64);
        }
        else {
            bufor += (txt[t] + c);
        }

        indexKey++;
        if (indexKey == key.size()) {
            indexKey = 0; 
        }
    }
        
    return bufor;
}

std::string deSzyfruj(std::string txt, std::string key) { 
    int indexKey = 0;
    std::string bufor;

    for (int t = 0; t < txt.size(); t++) {
        int a = txt[t] - 65;
        int b = key[indexKey] - 48;
        int c = 0;
        if (a - b < 0) {
            c = (a - b) * -1;
            bufor += char(91 - c);
        }
        else {
            bufor += char(int(txt[t]) - int(key[indexKey] - 48));
        }
        indexKey++;
        if (indexKey == key.size()) {
            indexKey = 0;
        }
    }
    return bufor;
}

int main() {
    
    std::string mode;//SZYFRUJ/DESZYFRUJ
    int key;
    std::string txt;

    std::cin >> mode;
    std::cin >> key;
    std::cin >> txt;

    if (mode == "SZYFRUJ") {
        std::cout << szyfruj(txt, std::to_string(key))<<std::endl;
    }
    else {
        std::cout << deSzyfruj(txt, std::to_string(key))<<std::endl;
    }

    return 0;

}
