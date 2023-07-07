

#include <stdio.h>

int main_1()
{
	register int a = 1;
	//register，建议将数据放在寄存器中
	//频繁被使用的数据，想放在寄存器中，提高效率
	//意义不大好像

	return 0;
}

typedef unsigned int u_int;//typedef类型重定义,重新取个名字
int main_2()
{
	unsigned int b = 1;//unsigned表示无符号的
	signed int c = -1;//signed表示有符号的
	u_int d = 1;


	return 0;
}