#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector {
	int EndState;
public:
	Dialog(void);
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
};

