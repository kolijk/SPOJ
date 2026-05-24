#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Pos {
    int x, y;
    Pos() = default;
    Pos(int x, int y): x(x), y(y) {}
};

float pitagoras(Pos a, Pos b) {
    int width = a.x - b.x; if (width < 0) { width *= -1; }
    int height = a.y - b.y; if (height < 0) { height *= -1; }

    int c2 = (width * width) + (height * height);

    float result = sqrt(c2);

    return result;

}

/*
a - wymiar szyby
r - promien wycieraczki    
positions - wspolrzedne owadow na szybie
*/
int check(int a, int r, std::vector <Pos> positions) {
    int bufor = 0;

    for (int x=0; x<positions.size(); x++) {
        if (pitagoras(Pos(a, 0), positions[x]) <= r) {
            bufor++;
        }
    }

    return positions.size() - bufor;
}

int main() {

   int a, r, n;
   std::cin >>a>>r>>n;
   std::cin.ignore();

   std::vector <Pos> positions;

   for (int x=0; x<n; x++) {
        int x_b, y_b;
        std::cin >>x_b>>y_b;
        positions.push_back(Pos(x_b, y_b));
   }

   std::cout <<check(a, r, positions)<<std::endl;

    return 0;
}
