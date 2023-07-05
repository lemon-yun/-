

#include <stdio.h>
//while

int main_3()
{
	int line = 1;
	while (line <= 30000)
	{
		printf("写代码：%d\n", line);
		line++ ;
	}
	if (line == 30001)
	{
		printf("好offer，继续努力");
	}
	return 0;
}
