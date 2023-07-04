

#define _CRT_SECURE_NO_WARNINGS 1  //详见scanf（44、45行）
#include <stdio.h>//引用头文件（？

int ABC = 3;//全局变量，在大括号外

extern int EFD;//声明变量，引用隔壁源文件的变量定义

int main_1()//一个工程或多个工程都只能有一个main，但可以main_1，不执行（？
{
	printf("hello world\n");//   \n是分行的意思
	printf("%d\n", ABC);//打印一个整数 —— %d（%ld、%Ld长整型，%hd短整型）
	printf("%d\n", EFD);
	printf("%d\n", 100);


	printf("%d\n", sizeof(char));//sizeof —— 计算类型或变量所占空间的大小
	printf("%d\n", sizeof(char));//字符数据类型
	printf("%d\n", sizeof(short));//短整型
	printf("%d\n", sizeof(int));//整型
	printf("%d\n", sizeof(long));//长整型
	printf("%d\n", sizeof(long long));//更长的整型
	printf("%d\n", sizeof(float));//单精度浮点型
	printf("%d\n", sizeof(double));//双精度浮点型


	int age = 16;//局部变量，在大括号内
	age = age + 1;
	printf("年龄 = %d\n", age);
	float weight = 62.0;
	double weight_1 = 62.0;
	printf("体重 = %.9f\n", weight);//输出浮点数，float用%f
	                             //（%.nf 这里n表示精确到小数位后n位）
	printf("体重 = %lf\n", weight_1);//输出浮点数，double用%lf
	

	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入两个整数，注意两个数之间用空格隔开\n");
	scanf("%d %d", &a, &b);//scanf —— 输入函数，可以在程序里输入数字
	//注意          &
	//直接使用scanf会出现错误，需要在所有代码的最上面（第一行）加上
	//“#define _CRT_SECURE_NO_WARNINGS 1”
	//也可以使用“scanf_s”代替“scanf”（但是，此函数是由VS提供的，不是C语言的）
	c = a + b;
	printf("您输入的数为%d %d,结果为%d\n",a, b, c);//一一对应


	char gameover = 'g';//注意单引号
	printf("%c\n", gameover);//输出一个字符%c
	printf("%c\n", 'h');
	char *victory = "gg";//注意星号和双引号
	printf("%s\n", victory);//输出一个字符串%s

	
	


	getchar();//按任意键继续
	return 0;
}


