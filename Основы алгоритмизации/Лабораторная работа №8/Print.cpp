#include "Print.h"
#include "Event.h"

Print::Print(void) { name = ""; author = ""; }
Print::~Print(void) {}
Print::Print(string N, string A) { name = N; author = A; }
Print::Print(const Print& print) { name = print.name; author = print.author; }
void Print::Set_name(string N) { name = N; }
void Print::Set_author(string A) { author = A; }

Print& Print::operator = (const Print& p) {
	if (&p == this) { return *this; }
	name = p.name;
	author = p.author;
		return *this;
}

void Print::Show() {
	cout << "\nНазвание: " << name;
	cout << "\nАвтор: " << author;
	cout << "\n";
}

void Print::Input() {
	cout << "\nНазвание: ";
	cin >> name;
	cout << "Автор: ";
	cin >> author;
}

void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage) {
		switch (e.command) {
		case cmGet:
			cout << "Название = " << Get_name() << endl;
			break;
		}
	}
}
