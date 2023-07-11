#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr2[] = { 0 };
void fanzhuan(char* a)
{
	int len = strlen(a);
	if (len > 1)
	{
		arr2[len-1] = *a;
		fanzhuan(a + 1);
	}
	else
	{
		arr2[len - 1] = *a;
	}
	
}
int main_1()
{
	char arr1[20] = { 0 };
	scanf("%s", arr1);
	int len = strlen(arr1);
	if (len > 2)
	{
		fanzhuan(arr1);
		printf("%s\n", arr2);
	}
	else
		printf("%s\n", arr1);
	getchar();
	getchar();
	return 0;
}



void fanzhuan2(char* a)
{
	int len = strlen(a);
	char tem = *a;
	*a = *(a + len - 1);
	*(a + len - 1) = '\0';
	if (len > 2)
	{
		fanzhuan(a + 1);
	}
	*(a + len - 1) = tem;

}
int main_2()
{
	while (1)
	{
		char arr[100] = { 0 };
		scanf("%s", arr);
		fanzhuan2(arr);
		printf("%s\n", arr);
	}

	return 0;
}