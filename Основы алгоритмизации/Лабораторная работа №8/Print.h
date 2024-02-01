#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

struct Print : public Object {
	Print(void);
	virtual ~Print(void);
	void Show();
	void Input();
	void HandleEvent(const TEvent&);
	Print(string, string);
	Print(const Print&);
	string Get_name() { return name; }
	string Get_author() { return author; }
	void Set_name(string);
	void Set_author(string);
	Print& operator = (const Print&);
protected:
	string name;
	string author;
};
