#include <iostream>
#include <string>

struct Data {
	int wszyscyUczniowie, zdalnie, stacjonarnie;
	Data() = default;
	Data(int v1, int v2): wszyscyUczniowie(v1), zdalnie(v2) { stacjonarnie = wszyscyUczniowie - zdalnie; }
};

Data prepare(std::string txt) {
	std::string num1, num2;

	bool space = false;
	for (int x=0; x<txt.size(); x++) {
		if (txt[x] == ' ') { 
			space = true; 
		}
		else {
			if (space == false) {
				num1 += txt[x];
			}else {
				num2 += txt[x];
			}
		}
	}

	return Data(std::stoi(num1), std::stoi(num2));

}

void display(int result) {
	std::cout <<result<<std::endl;
}

int main () {

	std::string txt[4];
	Data data[4];

	std::getline(std::cin, txt[0]);
	std::getline(std::cin, txt[1]);
	std::getline(std::cin, txt[2]);
	std::getline(std::cin, txt[3]);

	data[0] = prepare(txt[0]);
	data[1] = prepare(txt[1]);
	data[2] = prepare(txt[2]);
	data[3] = prepare(txt[3]);

	display(data[0].stacjonarnie + data[1].stacjonarnie + data[2].stacjonarnie + data[3].stacjonarnie);

	return 0;
}
