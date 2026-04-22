#include <iostream>
#include <string>

struct Position
{
    int x, y;
    Position() = default;
    Position(int x, int y): x(x), y(y) {}
};

void prepare(std::string txt, Position &a, Position &b) {
    std::string first, second;
    std::string *buf = &first;

    for (int x=0; x<txt.size(); x++) {
        if (txt[x] == ' ') {
            buf = &second; 
        }else {
            *buf += txt[x];
        }
    }

    a = Position(first[0] - 96, first[1] - 48);
    b = Position(second[0] - 96, second[1] - 48);

}

bool check(Position a, Position b) {
    
    Position posTab[8];

    posTab[0] = Position(a.x - 2, a.y - 1);
    posTab[1] = Position(a.x - 2, a.y + 1);
    posTab[2] = Position(a.x + 2, a.y - 1);
    posTab[3] = Position(a.x + 2, a.y + 1);
    posTab[4] = Position(a.x - 1, a.y + 2);
    posTab[5] = Position(a.x + 1, a.y + 2);
    posTab[6] = Position(a.x - 1, a.y - 2);
    posTab[7] = Position(a.x + 1, a.y - 2);

    for (int x=0; x<8; x++) {
        if (b.x == posTab[x].x && b.y == posTab[x].y) { return true; }
    }

    return false;
}

int main() {
    
    Position a, b;
    std::string txt;

    std::getline(std::cin, txt);

    prepare(txt, a, b);
    if (check(a, b) == true)
        std::cout <<"TAK" << std::endl;
    else
        std::cout << "NIE" << std::endl;

    return 0;
}
