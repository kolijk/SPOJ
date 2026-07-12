#include <iostream>
#include <string>

int calc(std::string txt) {

  //Two buffers for signs
    char buforFirst = txt[0];//Set first default sign
    char buforSecond = txt[txt.size()-1];//Set last default sign

    for (int x=0; x<txt.size(); x++) {
        if (txt[x] < buforFirst) {//If sign will be lowest sign in alphabet 
            buforFirst = txt[x];//Set sign as lowest than previous
        }
        if (txt[x] > buforSecond) {//If sign will be higher in alphabet than buffer
            buforSecond = txt[x];//Set sign as highest that prefious
        }
    }

    return buforSecond - buforFirst;//Calc different length for lowest and highest in buffers

}

int main() {

    int ile;
    std::string txt;

    std::cin >>ile;//Get how much will be sequences
    std::cin.ignore();//Ignore all blank signs

    for (int x=0; x<ile; x++) {
        std::getline(std::cin, txt);//Get sequence
        std::cout <<calc(txt)<<std::endl;//Display result
    }

    return 0;

}
