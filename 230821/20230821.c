

#include <stdio.h>
#include <stdlib.h>

int main_1()
{
	int* p = (int*)malloc(10*sizeof(int));//动态内存开辟
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",*(p + i));
	}
	free(p);//回收
	p = NULL;

	int* q = (int*)calloc(10,sizeof(int));//calloc会初始化，初始化为0
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(q + i));
	}
	free(q);
	q = NULL;

	int* o = (int*)malloc(10 * sizeof(int));
	int* ptr = (int*)realloc(p, 20);//修改p，开辟20字节
	if (ptr != NULL)
	{
		o = ptr;
	}
	free(o);
	o = NULL;
	return 0;
}