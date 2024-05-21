#include "Listing.h"

// Генерация исключения при текущий размер > максимальный размер
Listing::Listing(int s) {
	if (s > MAX_SIZE) { throw 1; }
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++) { 
		beg[i] = 0; 
	}
}

Listing::Listing(const Listing &l) {
	size = l.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) { 
		beg[i] = l.beg[i]; 
	}
}

Listing::~Listing() {
	if (beg != 0) { 
		delete[] beg; 
	}
}

Listing::Listing(int s, int *mas) {
	if (s > MAX_SIZE) { throw 1; }
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++) { 
		beg[i] = mas[i]; 
	}
}

const Listing& Listing::operator = (const Listing& l) {
	if (this == &l) { return *this; }
	if (beg != 0) { delete[]beg; }
	size = l.size;
	beg = new int[size];
	for (int i = 0; i < size; i++) { 
		beg[i] = l.beg[i]; 
	}
	return *this;
}

ostream& operator << (ostream& out, const Listing& l) {
	if (l.size == 0) { out << "Пусто\n"; }
	else {
		for (int i = 0; i < l.size; i++) { 
			out << l.beg[i] << " "; 
		}
		out << endl;
	}
	return out;
}

istream& operator >> (istream& in, Listing& l) {
	for (int i = 0; i < l.size; i++) { 
		cout << ">"; 
		in >> l.beg[i];
	}
	return in;
}
// Если индекс отрицательный, генерируется исключение
int Listing::operator [] (int i) { 
	if (i < 0) { 
		throw 2; 
	} 
}

Listing Listing::operator*(int a) {
	Listing temp(size, beg);
	size++;
	beg = new int[size];
	beg[0] = temp.beg[0] * temp.beg[a];
	return *this;
}