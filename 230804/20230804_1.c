

#include <stdio.h>
#include <ctype.h>


int main_1()
{
	char arr1[20] = "NHunbiuUBBIUFYUfu";
	int i = 0;
	while (arr1[i])
	{
		if (isupper(arr1[i]))
		{
			arr1[i] = tolower(arr1[i]);//��дתСд
		}
		printf("%c", arr1[i]);
		i++;
	}
	return 0;
}


#include <string.h>
void mymemcpy(void* a, void* b, int c)
{
	while (c--)
	{
		*((char*)a)++ = *((char*)b)++;//��׺�Ӽ����ȼ�����ǿ������ת��
	}
}
void mymemmove(void* a, void* b, int c)
{
	if (a < b)
	{
		while (c--)
		{
			*((char*)a)++ = *((char*)b)++;
		}
	}
	else
	{
		while (c--)
		{
			*((char*)a + c) = *((char*)b + c);
		}
	}
}
int main_3()
{
	//�ڴ��������
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[20] = { 0 };
	int arr3[10];
	memcpy(arr2, arr1, 20);//����ǰ���Ԫ��
	//memcpy�������ص����ڴ�(vs���memcpyҲ���Կ����ص���)

	memmove(arr1 + 2,arr1,20);
	//memmove���Կ����ص����ڴ�

	memcpy(arr1,arr2,12);//�Ƚ�ǰ����Ԫ��

	memset(arr3, 1, 20);
	//��ǰ20���ֽڶ�����Ϊ1
	return 0;
}




struct Ni
{
	char q;
	struct Ni* next;//�ṹ���������
};