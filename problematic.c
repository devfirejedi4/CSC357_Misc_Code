#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *ptr = (char *)malloc(10 * sizeof(char));
	char str[] = "CSC357";
	ptr = str;
	printf("%s\n", ptr);
	ptr[0] = 'P';
}