#pragma once
#include "Print.h"
#include <iostream>
using namespace std;

class Magazine : public Print {
	int page;
public:
	Magazine(void);
	~Magazine(void);
	void Show();
	void Input();
	Magazine(string, string, int);
	Magazine(const Magazine&);
	int Get_page() { return page; }
	void Set_Page(int);
	Magazine& operator = (const Magazine&);
};
