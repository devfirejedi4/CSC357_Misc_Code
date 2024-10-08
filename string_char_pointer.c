#include <stdio.h>

int main(void)
{
	char *charPtr;
	char charArr[] = "hello";
	charPtr = charArr;

	printf("before change: address charPtr is pointing to: %p\n", charPtr);
	printf("before change: address charArr is pointing to: %p\n", &charArr[0]);
	
	printf("before change: charPtr: %s\n", charPtr);
	printf("before change: charArr: %s\n\n", charArr);

	*charPtr = 'y';
	
	printf("after change: address charPtr is pointing to: %p\n", charPtr);
	printf("after change: address charArr is pointing to: %p\n", &charArr[0]);
	
	printf("after change: charPtr: %s\n", charPtr);
	printf("after change: charPtr: %s\n", charArr);
	
	return 0;
}




