#include <iostream>
#include <string>

int main () {
	
	std::string gest;

	std::getline(std::cin, gest);

	if (gest == "papier") { std::cout <<"nozyce"<< std::endl; }
	else if (gest == "kamien") { std::cout << "papier" << std::endl; }
	else if (gest == "nozyce") { std::cout << "kamien" << std::endl; }
	else { std::cout <<"przegrales"<< std::endl; }

	return 0;
}
