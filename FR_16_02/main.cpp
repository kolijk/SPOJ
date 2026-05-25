#include <iostream>
#include <string>
#include <vector>

int calcWyzyny(std::vector <int> heights) {
    int bufor = 0;
    for (int x = 1; x < heights.size() - 1; x++) {
        int a = heights[x - 1];
        int b = heights[x];
        int c = heights[x + 1];

        if (a < b && b > c) {
            bufor++;
        }

    }
    return bufor;
}

int main() {

   int N = 0;
   std::cin >>N;
   std::cin.ignore();

   std::vector <int> heights;

   for (int x=0; x<N; x++) {
       int bufor;
        std::cin >>bufor;
        heights.push_back(bufor);
   } 

   std::cout << calcWyzyny(heights)<<std::endl;

    return 0;
}
