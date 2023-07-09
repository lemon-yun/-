#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//在windows命令提示符里，关机指令
//shutdown -s -t 60(-s 关机，-t 设置倒计时， 60 60s后关机)
//shutdown -a（-a 取消关机）


int main_2()
{
	system("shutdown -s -t 60");//system("")用于执行系统命令，需引用stdlib.h
again://goto语句，注意  ：
	printf("你的电脑将在60s内关机，输入“不关”取消关机\n");
	char arr[100000] = { 0 };
	scanf("%s", arr);
	if ((strcmp(arr, "不关")) == 0)
	{
		system("shutdown -a");
		printf("已取消");
	}
	else
	{
		goto again;
	}
	return 0;
}