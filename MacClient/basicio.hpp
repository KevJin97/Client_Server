#pragma once

#include <string.h>
#include <stdio.h>

char *p_message()
{
	char input[513] = {NULL};
	
	printf("Enter command: ");
	scanf("%512s", input);
	
	return input;
}