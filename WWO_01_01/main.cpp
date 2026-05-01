#include <iostream>
#include <string>
#include <vector>

struct klasa {
    std::vector <std::string> womans;
    std::vector <std::string> mans;
    int howMuch;

    bool checkWomanName(std::string txt) {
        return (txt[txt.size() - 1] == 'a');
    }

    klasa() = default;
    
    klasa(std::string names, int howMuch) {
        this->howMuch = howMuch;
        names += ' ';
        
        std::string bufor;
        for (int x=0; x<names.size(); x++) {
            if (names[x] != ' ') {
                bufor += names[x];
            }else {
                if (bufor.size () > 0) {
                    if (checkWomanName(bufor) == true) {
                        womans.push_back(bufor);
                    }else {
                        mans.push_back(bufor);
                    }
                    bufor = "";
                }
            }
        }

    }
};

int main() {
    
    int d1, d2, d3;
    std::string dummy, names1, names2, names3;

    std::cin >> d1 >> d2 >> d3;//Get data ho much is peoples in class

    std::getline(std::cin, dummy);//Clear
    std::getline(std::cin, names1);//Get data
    std::getline(std::cin, names2);//Get data
    std::getline(std::cin, names3);//Get data

    klasa _3a, _3b, _4j;

    _3a = klasa(names1, d1);
    _3b = klasa(names2, d2);
    _4j = klasa(names3, d3);

    int sumWomans = _3a.womans.size() + _3b.womans.size() + _4j.womans.size();
    int sumMans = _3a.mans.size() + _3b.mans.size() + _4j.mans.size();

    int couples = sumWomans;

    if (sumMans < sumWomans) { couples = sumMans; }

    std::cout << couples <<std::endl;

    return 0;
}
