

#include <stdio.h>

void text1()//void，无，表示没有返回值，现在还搞不懂
{
	int f = 1;
	printf("%d ", f);
	f++;

}
void text2()
{
	static int h = 1;
	printf("%d ", h);
	h++;

}
//static，静态的，修饰局部变量，改变了变量的生命周期
//实质上改变了变量的存储类型，从栈区改到静态区
//在text2中，h不再销毁

static int i = 1;//static修饰的全局变量
                 //使其只能在所处的源文件中使用
                 //全局变量的外部链接属性在被修饰后
                 //变成了内部链接属性

static int add(int j, int k)//修饰后其他源文件无法再调用
{
	return j + k;
}
int main_3()
{
	int e = 0;
	while (e < 10)
	{
		text1();
		e++;
	}
	printf("\n");
	int g = 0;
	while (g < 10)
	{
		text2();
		g++;

	}



	return 0;
}