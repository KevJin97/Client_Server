#include <curses.h>
#include <stdio.h>
#include "cursordata.hpp"

int main()
{

	for(;;)
	{
		Coordinates data = mousecoordinate();
		printf("%d, %d\n", data.x, data.y);
	}
	
	return 0;
}
