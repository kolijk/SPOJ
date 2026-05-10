#include <iostream>
#include <string>
#include <set>
#include <vector>

struct Data {
    int n, x, y;
    Data() = default;
    Data(int n, int x, int y): n(n), x(x), y(y) {}
    int result;
};

std::set <int> calc(Data &data) {
    std::set <int> arr;

    for (int x=1; x<data.n; x++) {
        if (x % data.x == 0 && x % data.y != 0) {
            arr.insert(x);
        }
    }

    return arr;
}

void print(std::set <int> arr) {
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout <<*it<<" ";
    }
    std::cout << "\n";
}

Data prepare(std::string data) {
    std::string val1, val2, val3;
    std::string * ptr = &val1;

    for (int x=0; x<data.size(); x++) {
        if (data[x] != ' ') { 
            *ptr += data[x]; 
        }else {
            if (ptr == &val1) { ptr = &val2; }
            else if (ptr == &val2) { ptr = &val3; }
        }
    }

    return Data(std::stoi(val1), std::stoi(val2), std::stoi(val3));
}

int main() {
   
    int t;
    std::string txt;
    std::vector <Data> data; 

    std::cin >> t;
    std::cin.ignore();

    for (int x=0; x<t; x++) {
        std::getline(std::cin, txt);
        data.push_back(prepare(txt));
        print(calc(data[x]));
    }

    return 0;
}
