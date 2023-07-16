

#include <stdio.h>

int main_1()
{
	int arr[10] = { 1,22,34,35,2,56,2,5,2,5 };
	printf("%d", &arr[9] - &arr[0]);//结果为9，两个指针相减，结果为两个指针之间的元素个数
	//两个指针相减的前提，两个指针指向同一块空间
	return 0;
}

int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

int main()
{
	int len = my_strlen("abc");
	printf("%d", len);

	return 0;
}