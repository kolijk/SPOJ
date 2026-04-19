#include <iostream>
#include <string>

struct ST{
	int n1;
	int n2;
	int k1;
	int k2;
	ST() = default;
	ST(int n1, int n2, int k1, int k2): n1(n1), n2(n2), k1(k1), k2(k2) {}
};

ST prepare(std::string txt) {
	std::string n1, n2, k1, k2;

	std::string * buf = &n1;

	for (int x=0; x<txt.size(); x++) {
		if (buf != nullptr) {
			if (txt[x] != ' ') {
				*buf += txt[x];
			}else if (txt[x] == ' ') {
				if (buf == &n1) { buf = &k1; }
				else if (buf == &k1) { buf = &n2; }
				else if (buf == &n2) { buf = &k2; }
			}
		}
	}

	return ST(std::stoi(n1), std::stoi(n2), std::stoi(k1), std::stoi(k2));

}

int calc(ST st) {
	return (st.n1 * st.k1) + (st.n2 * st.k2);
}

void display(int pP) {
	std::cout <<pP<<std::endl;
}

void swap(int &a, int &b) {
	int buf = a;
	a = b;
	b = buf;
}

int main () {
	
	std::string txt;
	std::getline(std::cin, txt);

	display(calc(prepare(txt)));
	
	return 0;
}
