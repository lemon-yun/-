#include <stdio.h>


int main_1()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;//����ָ��
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
	}//��ѭ����&arr[15]�ĵ�ַ�պ���i�ĵ�ַ��arr[15] = 0 �͸պð�i��Ϊ0������forѭ��

	return 0;
}



void my_strcpy(char* arr1, char* arr2)
{
	while (*arr1++ = *arr2++)//����'\0'��ֵ��ȥ��\0��ASCII��ֵ��0��ѭ������
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