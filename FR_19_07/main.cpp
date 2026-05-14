#include <iostream>
#include <string>
#include <vector>

std::string emotikony[8] = {":)", ":(", ";)", ":D", ":P", "xD", ":>", "<3"};

//Prepare std::string sentence to std::vector
std::vector <std::string> prepare(std::string sentence) {
    sentence += " ";
    std::vector <std::string> bufor;
    std::string bufor2;

    for (int x=0; x<sentence.size(); x++) {
        if (sentence[x] == ' ') {
            bufor.push_back(bufor2);
            bufor2 = "";
        }else {
            bufor2 += sentence[x];
        }
    }

    return bufor;
}

//Check emotikony in word
bool check(std::string txt) {

    for (int x=0; x<8; x++) {
        if (txt == emotikony[x]) {
            return true;
        }
    }
    return false;
}

//Removing emotikony from sentence std::vector
void prepareSentence (std::vector <std::string>& slowa) {
    std::vector <std::string> bufor2;

    for (int x=0; x< slowa.size(); x++) {
        std::string bufor = slowa[x];
        if (check(bufor) == false) {
            bufor2.push_back(bufor);
        }
    }
    slowa = bufor2;
}

int main() {
   
    int liczba_wypowiedzi;
    std::cin >>liczba_wypowiedzi;
    std::cin.ignore();

    int liczba_slow;
    std::vector <std::string> slowa;
    std::string bufor;

    for (int x=0; x<liczba_wypowiedzi; x++) {
        std::cin >> liczba_slow;
        std::cin.ignore();
        std::getline(std::cin, bufor);
        slowa = prepare(bufor);
        prepareSentence(slowa);
        
        for (int y=0; y<slowa.size(); y++) {
            std::cout << slowa[y] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
