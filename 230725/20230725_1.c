

#include <stdio.h>

void print1(int(*p)[5])//������[5]
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}

int main_1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*parr)[10] = &arr;//����ָ��
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *((*parr) + i));
	}
	printf("\n");
	int arr1[3][5] = {1,2,3,4,5,2,3,4,5,6,3,4,5,6,7};
	print1(arr1);//��ά�����������ǵ�һ��Ԫ�صĵ�ַ

	int(*parr1[10])[5];//parr1��һ�����飬�ܴ��10������ָ�룬ÿ������ָ��ָ��һ������5��Ԫ�ص�����
 	return 0;
}


int main()
{
	//�ж�0~100000ˮ�ɻ���
	for (int i = 0; i <= 5000000000; i++)
	{
		//�ж�λ��
		int n = 1;
		int z = i;
		while (z / 10)
		{
			n++;
			z = z / 10;
		}
		//�����λn�η�֮��
		z = i;
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			int m = z % 10;
			int o = 1;
			for (int k = 1; k <= n; k++)
			{
				o = o * m;
			}
			sum = sum + o;
			z = z / 10;
		}
		//�ж��Ƿ�Ϊˮ�ɻ���
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}