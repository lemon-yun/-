

#include <stdio.h>
//while

int main_3()
{
	int line = 1;
	while (line <= 30000)
	{
		printf("д���룺%d\n", line);
		line++ ;
	}
	if (line == 30001)
	{
		printf("��offer������Ŭ��");
	}
	return 0;
}
