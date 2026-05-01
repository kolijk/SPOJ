#include <iostream>
#include <string>

//Prepare txt
std::string prepare(std::string txt, std::string letters) {
    std::string result;

    for (int x=0; x<txt.size(); x++) {
        result += txt[x];
        for (int y=0; y<letters.size(); y++) {
            if (letters[y] != ' ' && txt[x] == letters[y]) {
                result += letters[y];
            }
        }
    }

    return result;
}

int main() {
    
    int number;
    std::cin >>number;//Get number of letters to double
    std::string letters, txt;

    std::string bufor, c;
    std::getline(std::cin, c);//clear stream input
    std::getline(std::cin, letters);//get letters to double

    std::getline(std::cin, txt);//get txt for prepare

    std::cout <<prepare(txt, letters)<<std::endl;//Display result

    return 0;
}
