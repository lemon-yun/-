

#include <stdio.h>
#include <math.h>
//打印100~200之间的质数
//对于一个大于二的整数n，只要2~根号n之间没有n的因数，n为质数

int main_1()
{
	int a, b;
	for (a = 101; a <= 200; a += 2)
	{
		int c = 1;
		for (b = 2; b <= sqrt(a); b++)//sqrt，开平方，需引用math.h
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