#include <iostream>
#include <string>

char tab[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int calcValue(std::string sequence) {
    int sum = 0;

    for (int x=0; x<sequence.size(); x++) {
        for (int y = 0; y < 13; y++) {
            if (sequence[x] == tab[y]) {
                sum += (y + 2);
            }
        }
    }

    return sum;
}

int main() {

    std::string sequenceJas;
    std::string sequenceStas;

    std::cin >>sequenceJas>>sequenceStas;

    int valueJas = calcValue(sequenceJas);
    int valueStas = calcValue(sequenceStas);

    if (valueJas > valueStas) {
        std::cout <<"JASIO"<< std::endl;
    }else if (valueJas < valueStas) {
        std::cout << "STASIO" << std::endl;
    }else {
        std::cout << "REMIS" << std::endl;
    }

    return 0;
}
