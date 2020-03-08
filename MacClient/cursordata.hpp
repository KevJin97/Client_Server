#ifndef CURSORDATA_HPP
#define CURSORDATA_HPP

#include <curses.h>
#include <stdio.h>

struct Coordinates
{
	int x;
	int y;
};

Coordinates mousecoordinate()
{
	 Coordinates data;
	
	initscr();
	cbreak();
	noecho();
	
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	
	char buffer[512];
	size_t max_size = sizeof(buffer);
	
	int c = wgetch(stdscr);
	if (c == ERR)
	{
		snprintf(buffer, max_size, "Nothing happened\n");
	}
	else if (c == KEY_MOUSE)
	{
		MEVENT event;
		if (getmouse(&event) == OK)
		{
			data.x = event.x;
			data.y = event.y;
		}
		else
		{
			snprintf(buffer, max_size, "Got bad mouse event.");
		}
	}
	else
	{
		snprintf(buffer, max_size, "Pressed key %d (%s)", c, keyname(c));
	}
	endwin();

	return data;
}

#endif
