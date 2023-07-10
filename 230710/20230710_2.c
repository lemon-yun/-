


#include <stdio.h>
#include "sub.h"//引用手写头文件，注意  ""


int main_3()
{
	int a = 10;
	int b = 20;
	int c = sub(a, b);
	printf("%d", c);
	return 0;
}