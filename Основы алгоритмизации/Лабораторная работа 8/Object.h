// pragma once - подключение файла при компил€ции только один раз
#pragma once
#include <string>
#include "Event.h"
using namespace std;

struct Object
{
	Object(void) {};
	virtual ~Object(void) {};
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual void HandleEvent(const TEvent& e) = 0;
protected:
	string name;
	string author;
};

