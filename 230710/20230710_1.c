

#include <stdio.h>

int main_1()
{
	printf("%d ", printf("%d ", printf("%d ", 33)));
	//结果是33 3 2，printf返回的是打印到屏幕上的字符个数（空格也算）
	//有值才会打印，所以先打印33，再打印3，最后打印2
	return 0;
}



int main_2()
{
	int a = 10;
	int b = 20;
	int add(int, int);//如果自定义函数在主函数下方，需要先声明函数
	//函数的声明一般放在头文件里面
	int c = add(a, b);
	printf("%d", c);
	return 0;
}
//函数的定义
int add(int x, int y)
{
	return x + y;
}

