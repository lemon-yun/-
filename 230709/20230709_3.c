#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main_3()
{
	char arr1[20] = { 0 };
	char arr2[] = "hello world!";
	strcpy(arr1, arr2);//���ڶ�����ַ�е��ַ�����������һ����ַ��������string.h
	printf("%s", arr1);
	return 0;
}


int main_4()

{
	char arr[] = "hello world!";
	memset(arr, 'x', 5);
	//memset(��ַa, ����b, n)������ַa�е�ǰn���ַ���Ϊ����b

	return 0;
}

//���Զ��庯��������������λ�ã�ʹ��ָ���ں�����Ӱ����������ֵ
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
	printf("����ǰ a = %d, b = %d\n", a, b);
	ex(&a, &b);
	printf("������ a = %d, b = %d\n", a, b);
	return 0;
}


