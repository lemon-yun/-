

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stu
{
	char name[20];
	int age;
};

int Sort_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1) -> name, ((struct stu*)e2)->name);
}
int Sort_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
int main_1()
{
	struct stu S[3] = { {"zhangsan", 16} ,{"lisi", 18} ,{"wangwu", 17}};
	int sz = sizeof(S) / sizeof(S[0]);
	qsort(S, sz, sizeof(S[0]),Sort_by_name);//qsort 数组快捷排序,需引用stdlib.h
	//（数组名，数组元素个数，数组元素大小，自己写个比较函数）
	//qsort(S, sz, sizeof(S[0]), Sort_by_age);
	return 0;
}



void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
int Sort_by_num(const void* e1, const void* e2)
{
	return (*(int*)e1) - (*(int*)e2);
}
void Exc(char* e1, char* e2, int size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *(e1 + i);
		*(e1 + i) = *(e2 + i);
		*(e2 + i) = tmp;
	}
}
void Mine_sort(void* arr, int sz, int size, int (*S_b_m)(const void*, const void*))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (S_b_m ((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0)
			{
				Exc((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}
//自己实现qsort
int main()
{
	int arr[10] = {121,235,236,6,244,6,472,246,2,78};
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	Mine_sort(arr,sz, sizeof(arr[0]), Sort_by_num);
	print(arr, sz);
	struct stu S[3] = { {"zhangsan", 16} ,{"lisi", 18} ,{"wangwu", 17} };
	int sz2 = sizeof(S) / sizeof(S[0]);
	//Mine_sort(S, sz2, sizeof(S[0]), Sort_by_name);
	Mine_sort(S, sz2, sizeof(S[0]), Sort_by_age);
	return 0;
}