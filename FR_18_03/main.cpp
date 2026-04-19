#include <iostream>
#include <string>

struct ST{
	int a;
	int b;
	int c;
	int d;
	ST() = default;
	ST(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
};

ST prepare(std::string txt) {
	std::string a, b, c, d;

	std::string * buf = &a;

	for (int x=0; x<txt.size(); x++) {
		if (buf != nullptr) {
			if (txt[x] != ' ') {
				*buf += txt[x];
			}else if (txt[x] == ' ') {
				if (buf == &a) { buf = &b; }
				else if (buf == &b) { buf = &c; }
				else if (buf == &c) { buf = &d; }
			}
		}
	}

	return ST(std::stoi(a), std::stoi(b), std::stoi(c), std::stoi(d));

}

int calc(ST st) {
	return (st.b * st.d);
}

void display(int pP) {
	std::cout <<pP<<std::endl;
}

void swap(int &a, int &b) {
	int buf = a;
	a = b;
	b = buf;
}

ST sort(ST st) {
	
	do {
		if (st.d > st.c) { swap(st.d, st.c); }
		if (st.c > st.b) { swap(st.c, st.b); }
		if (st.b > st.a) { swap(st.b, st.a); }
	} while (st.a < st.b || st.b < st.c || st.c < st.d);
	
	return st;
}

int main () {
	
	std::string txt;
	std::getline(std::cin, txt);

	display(calc(sort(prepare(txt))));
	
	return 0;
}
