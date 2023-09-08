#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

struct S
{
	char a[10];
	int b;
	float c;
};
int main_1()
{
	struct S s = { "abc", 1, 5.5 };
	char ip[20] = { 0 };
	sprintf(ip, "%s %d %f", s.a, s.b, s.c);//空格要加，不然后面可能会读取错误
	//sprintf 把格式化的数据写为字符串
	printf("%s\n", ip);
	printf("%d\n", strlen(ip));

	printf("\n");

	struct S b = { 0 };
	sscanf(ip, "%s %d %f", b.a, &b.b, &b.c);//可不加空格
	//sscanf 从字符串里读取格式化的数据
	printf("%s %d %f", b.a, b.b, b.c);

	return 0;
}


int main_2()
{
	FILE* pf = fopen("text.txt", "r");
	if (!pf)
	{
		return 1;
	}
	//随机读写
	char ch = fgetc(pf);
	printf("%c\n", ch);//a

	fseek(pf, -1, SEEK_CUR);//从当前指针位置的 -1 位置读写
	//所以下一个的输出结果也是a
	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, -2, SEEK_END);//从文件末尾位置的 - 位置读写
	//所以下一个的输出结果是e
	ch = fgetc(pf);
	printf("%c\n", ch);

	fseek(pf, 3, SEEK_SET);//从文件开头位置的 3 位置读写
	//所以下一个的输出结果是d
	ch = fgetc(pf);
	printf("%c\n", ch);

	ch = fgetc(pf);
	printf("%c\n", ch);//e

	int p = ftell(pf);//返回文件指针相当于起始位置的偏移量
	printf("%d\n", p);

	rewind(pf);//让文件指针回到初始位置开始都写
	ch = fgetc(pf);
	printf("%c\n", ch);//a

	fclose(pf);
	pf = NULL;
	return 0;
}


int main()
{
	FILE* pr = fopen("text2.txt", "r");
	if (!pr)
	{
		return 1;
	}
	FILE* pw = fopen("tect3.txt", "w");
	if (!pw)
	{
		return 2;
	}

	char ch = 0;
	while ((ch = fgetc(pr)) != EOF)
	{
		fputc(ch,pw);
	}
	if (feof(pr))
		//读取到文件末尾结束feof返回一个非零值，如果不是文件指针不是在文件末尾返回0
		//There is no error return.(这是说不会返回错误码吗？)
	{
		printf("正常读取结束");
	}
	else if (ferror(pr))//有错误返回对应非0错误码
	{
		printf("文件读取失败结束");
	}

	fclose(pr);
	pr = NULL;
	fclose(pw);
	pw = NULL;
	return 0;
}

