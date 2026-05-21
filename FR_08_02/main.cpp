#include <iostream>
#include <string>
#include <vector>

struct Status{
    int loses;
    int wins;
    Status(int loses, int winds): loses(loses), wins(wins) {}
    Status() = default;
};

//Prepare data from std::string to structs
void prepare(std::string txt, Status &Stas, Status &Wies, Status &Grzes) {

    txt += ' ';

    int counter = 0;
    std::string bufor;
    for (int x=0; x<txt.size(); x++) {
        if (txt[x] == ' ') {
            switch (counter)
            {
            case 0:
                Stas.wins = std::stoi(bufor);
                break;
            case 1:
                Stas.loses = std::stoi(bufor);
                break;
            case 2:
                Wies.wins = std::stoi(bufor);
                break;
            case 3:
                Wies.loses = std::stoi(bufor);
                break;
            case 4:
                Grzes.wins = std::stoi(bufor);
                break;
            case 5:
                Grzes.loses = std::stoi(bufor);
                break;
            }
            bufor = "";
            counter++;
        }else {
            bufor += txt[x];
        }
    }

}

//Calc wins & lost games for Jas
Status calcJas(Status Stas, Status Wies, Status Grzes) {

    Status status;
    status.loses = 0;
    status.wins = 0;

    int sumWins = Stas.wins + Wies.wins + Grzes.wins;
    int sumLoses = Stas.loses + Wies.loses + Grzes.loses;

    int playesCount = Stas.wins + Stas.loses;

    if (sumWins < sumLoses) {
        playesCount -= sumLoses - sumWins;
        status.wins += sumLoses - sumWins;
        sumWins += sumLoses - sumWins;
    }else {
        playesCount -= sumWins - sumLoses;
        status.loses += sumWins - sumLoses;
        sumLoses += sumWins - sumLoses;
    }

    status.wins += playesCount / 2;
    status.loses += playesCount / 2;

    return status;
}

//Display
void display(Status Jas) {
    std::cout <<Jas.wins<<" "<<Jas.loses << std::endl;
}

int main() {

    int howMuch = 0;
    std::cin >>howMuch;
    std::cin.ignore();

    std::string dataBuf;

    Status Stas;
    Status Wies;
    Status Grzes;
    Status Jas;

    for (int x=0; x<howMuch; x++) {
        std::getline(std::cin, dataBuf);//Get data about test
        prepare(dataBuf, Stas, Wies, Grzes);//Prepare data for kids
        display(calcJas(Stas, Wies, Grzes));//calc & display data
    }
    
    return 0;
}
