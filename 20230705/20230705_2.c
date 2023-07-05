#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//选择语句

int main_2()
{
	int a = 0;
	printf("下雨了吗？（1/0）：");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("带把伞吧");
	}
	else
	{

		printf("带把伞以防万一");
	}
	
	return 0;
}
