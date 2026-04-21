#include <iostream>
#include <string>
#include <vector>

struct Mix{
	int i;
	int j;
	Mix() = default;
	Mix(std::string ij){
		std::string l, r;

		bool space = false;
		for (int x=0; x<ij.size(); x++) {
			if (ij[x] == ' ') {
				space = true;
			}else {
				if (space == false) {
					l += ij[x];
				}else {
					r += ij[x];
				}
			}
		}

		i = std::stoi(l);
		j = std::stoi(r);
	}
};

void changePositions(std::vector <int> &idCups, Mix mix) {
	int buf = idCups[mix.i-1];
	idCups[mix.i - 1] = idCups[mix.j - 1];
	idCups[mix.j - 1] = buf;
}

int main () {
	
	int howMuchCup, howMuchMixCups, i, j;
	std::string ij;

	std::cin >> howMuchCup;
	std::cin >> howMuchMixCups;

	std::vector <Mix> mix;//Ktory z ktorym kubkiem
	std::vector <int> idCups;

	for (int x=0; x<howMuchCup; x++) {//Uzupelniam wektor kubkow indentyfikatorami
		idCups.push_back(x+1);
	}

	while (std::getline(std::cin, ij)) {//Pobieram kolejne pozycje zamian kubkow
		if (ij.size() > 0) {
			mix.push_back(Mix(ij));
		}
	}

	for (int x=0; x<mix.size(); x++) {//Miksuje kubki
		if (mix[x].i != mix[x].j) {
			changePositions(idCups, mix[x]);
		}
	}

	for (int x=0; x<idCups.size(); x++) {//Wyswietlam id
		std::cout <<idCups[x]<<std::endl;
	}


	return 0;
}
