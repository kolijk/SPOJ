#include <iostream>
#include <string>



int main() {
    
    std::string txt;
    std::getline(std::cin, txt);

    if (txt[0] == txt[3] || txt[1] == txt[4])
        std::cout <<"TAK" << std::endl;
    else
        std::cout << "NIE" << std::endl;

    return 0;
}
