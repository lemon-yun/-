

#include <stdio.h>
#include <stdlib.h>

int main_1()
{
	int* p = (int*)malloc(10*sizeof(int));//��̬�ڴ濪��
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",*(p + i));
	}
	free(p);//����
	p = NULL;

	int* q = (int*)calloc(10,sizeof(int));//calloc���ʼ������ʼ��Ϊ0
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", *(q + i));
	}
	free(q);
	q = NULL;

	int* o = (int*)malloc(10 * sizeof(int));
	int* ptr = (int*)realloc(p, 20);//�޸�p������20�ֽ�
	if (ptr != NULL)
	{
		o = ptr;
	}
	free(o);
	o = NULL;
	return 0;
}