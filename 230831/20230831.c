


#include <stdio.h>
#include <malloc.h>

struct S
{
	int n;
	int arr[0];//�ṹ����������飬c99�����������Աǰ���ٻ�����1����Ա
	//���������Ա��С�ɱ�
};


int main_1()
{
	//��������ʹ�÷�ʽ
	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));//��̬���ٿռ�
	if (!p)
	{
		return 1;
	}
	p->n = 10;
	for (int i = 0; i < 10; i++)
	{
		p->arr[i] = i + 1;
	}
	struct S* ptr = (struct S*)realloc(p, sizeof(struct S) + 20 * sizeof(int));//ʹ��realloc����
	if (ptr)
	{
		p = ptr;
	}
	for (int i = 10; i < 20; i++)
	{
		p->arr[i] = i + 1;
	}

	free(p);
	p = NULL;

	return 0;
}


//ģ����������
struct B
{
	int n;
	int* arr;
};

int main_2()
{
	struct B* p = (struct B*)malloc(sizeof(struct B));
	if (!p)
	{
		return 1;
	}
	p->n = 10;

	p->arr = (int*)malloc(10 * sizeof(int));
	if (!p->arr)
	{
		return 1;
	}
	for (int i = 0; i < 10; i++)
	{
		p->arr[i] = i + 1;
	}

	int* ptr = (int*)realloc(p->arr, 20 * sizeof(int));
	if (ptr)
	{
		p->arr = ptr;
	}

	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;


	return 0;
}

//int main()
//{
//	struct B* p = (struct B*)malloc(sizeof(struct B) + 10 * sizeof(int));
//	if (!p)
//	{
//		return 1;
//	}
//	p->n = 10;
//	for (int i = 4; i < 10; i++)
//	{
//		p->arr[i] = i + 1;
//	}
//	
//
//	free(p);
//	p = NULL;
//	return 0;
//}������