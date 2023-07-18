#include <stdio.h>


int main_1()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;//二级指针
	**ppa = 20;
	printf("%d", a);
	return 0;
}


struct B
{
	char a[20];
	int b;
};

struct stu
{
	struct B ab;
	char name[50];
	int age;
};

int main_2()
{
	struct stu zhangsan = { {"wdnmd", 20}, "zhangsan", 17 };
	printf("%s %d %s %d\n", zhangsan.ab.a, zhangsan.ab.b, zhangsan.name, zhangsan.age);
	zhangsan.age = 18;
	printf("%s %d %s %d\n", zhangsan.ab.a, zhangsan.ab.b, zhangsan.name, zhangsan.age);
	return 0;
}


int main_3()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;

	for (i = 0; i <= 15; i++)
	{
		arr[i] = 0;
		printf("ab\n");
	}//死循环，&arr[15]的地址刚好是i的地址，arr[15] = 0 就刚好把i改为0，重新for循环

	return 0;
}



void my_strcpy(char* arr1, char* arr2)
{
	while (*arr1++ = *arr2++)//当把'\0'赋值过去后，\0的ASCII码值是0，循环结束
	{
		;
	}
}

int main()
{
	char arr1[10] = "xxxxxxxxxx";
	char arr2[] = "hello";
	my_strcpy(arr1, arr2);
	printf("%s", arr1);
	return 0;
}