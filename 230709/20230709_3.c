#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main_3()
{
	char arr1[20] = { 0 };
	char arr2[] = "hello world!";
	strcpy(arr1, arr2);//将第二个地址中的字符串拷贝至第一个地址，需引用string.h
	printf("%s", arr1);
	return 0;
}


int main_4()

{
	char arr[] = "hello world!";
	memset(arr, 'x', 5);
	//memset(地址a, 整型b, n)，将地址a中的前n个字符改为整型b

	return 0;
}

//用自定义函数交换两个数的位置，使用指针在函数中影响主函数的值
void ex(int* px, int* py)
{
	int z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("交换前 a = %d, b = %d\n", a, b);
	ex(&a, &b);
	printf("交换后 a = %d, b = %d\n", a, b);
	return 0;
}


