#pragma once
#include "Object.h"

struct Vector {
	Vector(int);
	~Vector(void);
	Vector();
	void Add();
	void Del();
	void Show();
	int operator() ();
protected:
	int size;
	int cur;
	Object** beg;
	void HandleEvent(const TEvent& e);
};
