#include <iostream>
#include <string>

//Function who prepare input data
std::string prepareData(std::string txt) {
    
    std::string bufor;
    bufor += txt[0];

    for (int x=0; x<txt.size(); x++) {
        if (x-1 >=0 && txt[x - 1] == '.') {//If will be sign '.' insert to result space sign
            bufor += ' ';
        }
        if (txt[x] == ' ' && x+1 < txt.size()) {//If will be sign space next sign add to result
            bufor += txt[x+1];
        }
    }

    return bufor;//Return result

}

int main() {

    std::string txt;

    while (std::getline(std::cin, txt)) {//Get data
        std::cout<<prepareData(txt)<<std::endl;//prepare and display data input
    }

    return 0;

}
