#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Data {
    int a1, a2;
    int result;
    Data() = default;
    Data(int a1, int a2): a1(a1), a2(a2) {};
};

Data prepare(std::string txt) {
    std::string first, second;
    std::string *ptr = &first;

    for (int x=0; x<txt.size(); x++) {
        if (txt[x] == ' ') { ptr = &second; }
        else {
            *ptr += txt[x];
        }
    }

    return Data(std::stoi(first), std::stoi(second));
}

Data calc(Data dt) {
    
    if (dt.a1 == dt.a2) {//If both players have same moneys
        dt.result = dt.a1 + dt.a2;
        return dt;
    }
    else if (dt.a1 > dt.a2) {//If player first have more money than second player
        dt.a1 -= dt.a2;
        dt = calc(dt);
    }
    else if (dt.a1 < dt.a2) {//If player second have more money than first player
        dt.a2 -= dt.a1;
        dt = calc(dt);
    }

    return dt;

}

int main() {
    
    std::vector <Data> datas;

    int parts_t;
    std::cin >>parts_t;//Get parts
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Ignore from std::cin in bufor sign end of line

    for (int x=0; x<parts_t; x++) {
        std::string a1b1;
        std::getline(std::cin, a1b1);//get data for part
        datas.push_back(prepare(a1b1));//Add data part to vector
    }

    for (int x = 0; x < datas.size(); x++) {
        datas[x] = calc(datas[x]);//Calc result for part
        std::cout <<datas[x].result<<std::endl;//Display result for this part
    }


    return 0;
}
