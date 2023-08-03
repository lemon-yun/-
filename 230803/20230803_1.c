#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <errno.h>

int main_1()
{

	FILE* pf = fopen("text.txt", "r");
	if (pf == NULL)
	{
		perror("");//同样是打印错误信息，但比strerror更简单
		return errno;
	}
	fclose(pf);
	pf = NULL;
	return 0;
}

#include <ctype.h>
int main()
{
	char ch = '4';
	int ret = isdigit(ch);//判断一个字符是不是数字字符（注意是字符），不是返回0，是返回非零数字
	//需引用ctype.h
	printf("%d", ret);
	return 0;
}