#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	int l, r, x, y;
	scanf("%d", &l);
	scanf("%d", &r);
	scanf("%d", &x);
	scanf("%d", &y);

	int sum = 0;

	if (x != y && x != 0 && y != 0)
	{
		for (int i = l; i <= r; i++)
		{
			if (i % x == 0)
			{
				sum = sum + (i / x);
			}
		}
		for (int i = l; i <= r; i++)
		{
			if (i % y == 0)
			{
				sum = sum + (i / y);
			}
		}
		if (x == 1)
		{
			for (int i = l; i <= r; i++)
			{
				if (i % y == 0)
				{
					sum = sum + ((i / y) * 2);
				}
			}
		}
		else if (y == 1)
		{
			for (int i = l; i <= r; i++)
			{
				if (i % x == 0)
				{
					sum = sum + ((i / x) * 2);
				}
			}
		}
		else if (x != 1 && y != 1)
		{
			for (int i = l; i <= r; i++)
			{
				if (i % x == 0)
				{
					for (int j = l; j <= r; j++)
					{
						if (j % y == 0)
						{
							int a = (j / x);
							int b = (j / y);
							int c = a + b;
							int ret = 1;
							for (int k = a; k > 0; k--)
							{
								ret = ret * c;
								c--;
							}
							sum += ret;
						}
					}
				}
			}
		}
	}
	else if (x == y && x != 0 && x != 1)
	{
		for (int i = l; i <= r; i++)
		{
			if (i % x == 0)
			{
				sum = sum + pow(2, (int)(i / x));
			}
		}
	}
	else if (x == y && x == 0)
	{
		printf("0");
		return 0;
	}
	else if (x != 0 && y == 0)
	{
		for (int i = l; i <= r; i++)
		{
			if (i % x == 0)
			{
				sum = sum + (i / x);
			}
		}
	}
	else if (x == 0 && y != 0)
	{
		for (int i = l; i <= r; i++)
		{
			if (i % y == 0)
			{
				sum = sum + (i / y);
			}
		}
	}
	else if (x == y && x == 1)
	{
		int ret = r - l + 1;
		for (int i = 1; ret > 0; ret--)
		{
			i = i + ret;
		}
		sum += ret;
		for (int i = l; i <= r; i++)
		{
			for (int j = l; j <= r; j++)
			{

			}
		}
	}
	printf("%d", sum);
	return 0;
}
