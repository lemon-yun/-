

#include <stdio.h>
#include <math.h>
//��ӡ100~200֮�������
//����һ�����ڶ�������n��ֻҪ2~����n֮��û��n��������nΪ����

int main_1()
{
	int a, b;
	for (a = 101; a <= 200; a += 2)
	{
		int c = 1;
		for (b = 2; b <= sqrt(a); b++)//sqrt����ƽ����������math.h
		{
			if (a % b == 0)
			{
				c--;
				break;
			}
		}
		if (c == 1)
			printf("%d ", a);
	}

	return 0;
}