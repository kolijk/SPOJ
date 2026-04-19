//FR_16_03 - Snake case na camel case
#include <iostream>
#include <string>

std::string prepare(std::string txt) {
	std::string bufor;

	for (int x = 0; x < txt.size(); x++) {
		if (txt[x] == ' ') {
			txt[x] = '_';
		}
	}

	for (int x = 0; x < txt.size() - 1; x++) {
		if (txt[x] == '_' && (txt[x + 1] >= 'a' && txt[x + 1] <= 'z')) {
			txt[x + 1] -= 32;
		}
	}

	for (int x = 0; x < txt.size(); x++) {
		if (txt[x] != '_') {
			bufor += txt[x];
		}
	}

	return bufor;
}

void display(std::string txt) {
	std::cout << txt << std::endl;
}

int main() {

	std::string txt;
	std::getline(std::cin, txt);

	display(prepare(txt));

	return 0;
}
