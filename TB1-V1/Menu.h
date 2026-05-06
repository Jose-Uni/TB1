#pragma once
#include "Contact.h"
#include "ContactList.h"
#include "Opportunities.h"
#include "OpportunityList.h"
#include "LeadQueue.h"
#include "header.h"

class Menu {
private:
	int x, y;
	CONSOLE_CURSOR_INFO cursorVisible;
	HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	Menu() {
		this->x = 0;
		this->y = 0;
		cursorVisible.bVisible = FALSE;
		cursorVisible.dwSize = 1;
		SetConsoleCursorInfo(hConsol, &cursorVisible);
	}
	~Menu() {};
};
