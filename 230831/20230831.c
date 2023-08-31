


#include <stdio.h>
#include <malloc.h>

struct S
{
	int n;
	int arr[0];//结构体的柔性数组，c99，柔性数组成员前至少还得有1个成员
	//柔性数组成员大小可变
};


int main_1()
{
	//柔性数组使用方式
	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));//动态开辟空间
	if (!p)
	{
		return 1;
	}
	p->n = 10;
	for (int i = 0; i < 10; i++)
	{
		p->arr[i] = i + 1;
	}
	struct S* ptr = (struct S*)realloc(p, sizeof(struct S) + 20 * sizeof(int));//使用realloc增加
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


//模拟柔性数组
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
//}有问题