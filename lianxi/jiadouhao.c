#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>
#include <malloc.h>


void Addcomma(char** p, int n, int xz, int len, int ip2)
{
	*(*p + len + n) = '\0';

	if (xz != 0)
	{
		len -= xz;
		*p += xz;
		for (int i = len; i > 0; i--)
		{
			*(*p + i) = *(*p + i - 1);
		}
		**p = ',';
		n--;
		*p += 1;
	}
	for (int i = n; i > 0; i--)
	{
		*p += ip2;
		len -= ip2;
		for (int j = len; j > 0; j--)
		{
			*(*p + j) = *(*p + j - 1);
		}
		**p = ',';
		n--;
		*p += 1;
	}
}

int main_1()
{
	int ip1;//获得数字位数
	scanf("%d", &ip1);
	int ip2;//获得每隔几位
	scanf("%d", &ip2);
	int n = ip1 / ip2;//逗号个数
	int xz = ip1 % ip2;//修正
	if (xz == 0)
	{
		n -= 1;
	}
	char* ip3 = (char*)malloc(ip1+1+n);//动态开辟空间
	scanf("%s", ip3);


	if (n == 0)
	{
		printf("%s", ip3);
	}
	else
	{
		char* p1 = ip3;
		Addcomma(&ip3,n,xz,ip1,ip2);
		printf("%s", p1);
	}
	return 0;
}
