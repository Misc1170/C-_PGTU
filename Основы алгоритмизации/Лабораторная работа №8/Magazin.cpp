#include "Magazin.h"

Magazine::Magazine(void) : Print () { page = 0; }
Magazine::~Magazine(void) {}
Magazine::Magazine(string N, string A, int P) : Print (N, A) { page = P; }
Magazine::Magazine(const Magazine &M) { name = M.name; author = M.author; page = M.page; }
void Magazine::Set_Page(int P) { page = P; }

Magazine& Magazine::operator = (const Magazine& m) {
	if (&m == this) { return *this; }
	name = m.name;
	author = m.author;
		return *this;
}

void Magazine::Show() {
	cout << "\n�������� : " << name;
	cout << "\n����� : " << author;
	cout << "\n�������� : " << page;
	cout << "\n";
}

void Magazine::Input() {
	cout << "\n�������� : ";
	cin >> name;
	cout << "����� : ";
	cin >> author;
	cout << "�������� : ";
	cin >> page;
}