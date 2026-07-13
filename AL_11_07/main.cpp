#include <iostream>
#include <string>

//function swap both signs
void swap(char& one, char& second) {

    char buffer = one;

    one = second;

    second = buffer;

}

//Function decoded text
std::string decode(std::string data) {

    for (int x=0; x<data.size()-1;) {
        swap(data[x], data[x+1]);//Swap first+x and second+x letters
        x+=2;
    }

    return data;//return result

}

int main() {

    std::string data;

    while (std::getline(std::cin, data)) {//Get all data
        std::cout <<decode(data)<<std::endl;//Decode and display result
    }

    return 0;

}
