
#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main_9()
{
	int a;
	scanf("%d", &a);
	if (a <= 10)
		printf("1");
	else if (a > 10 && a <= 18)//注意，10<a<=的写法是不被允许的
		printf("2");
	else
		printf("3");
	return 0;
}


int main_10()
{
	int a, b;
	for (a = 1; a <= 100; a++)//分号隔开

	{
		if (a % 2 == 1)
			printf("%d ", a);
	}
	return 0;
}


int main()
{
	int day;
	scanf("%d", &day);
	switch (day)//括号里需要是整型
	{
	case 1://case后面是整型常量表达式，注意  ：
		printf("星期一");
		break;//break跳出
	case 2:
		printf("星期二");
		break;
	case 3:
		printf("星期三");
		break;
	case 4:
		printf("星期四");
		break;
	case 5:
		printf("星期五");
		break;
	case 6:
		printf("星期六");
		break;
	case 7:
		printf("星期天");
		break;
	default://默认，其他情况
		printf("错误");
		break;
	}
	return 0;
}