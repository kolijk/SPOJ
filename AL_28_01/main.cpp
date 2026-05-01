#include <iostream>
#include <string>

int main() {
    
    std::string txt;
    int length;
    std::cin >> length;
    std::cin >> txt;

    int centerIndex = (txt.size() - 1) / 2;//Calc center sign

    for (int y = 0; y < centerIndex + 1; y++) {
        for (int x = 0; x < length; x++) {
            int l = centerIndex - y;//left border for display letters
            int r = centerIndex + y;//right border for display letters
            
            if (x >= l && x <= r) {//When variable x is beetwen l & r display letter
                std::cout <<txt[x];
            }else {
                std::cout << '.';//When variable x is out range l & r display sign dot '.'
            }
        }
        std::cout <<"\n";//New line
    }

    return 0;
}
