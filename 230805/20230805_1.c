

#include <stdio.h>

//结构体的内存对齐
//1.第一个成员在结构体变量偏移值为0的地址处
//2.其它成员变量要对齐到对齐数的整数倍数的地址处
//  对齐数=编译器默认的一个对齐数 与 该成员大小的较小值
//  vs默认为8
//3.结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍
//4.如果嵌套了结构体，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
//所有最大对齐数（含嵌套结构体的对齐数）的整数倍

#pragma pack(2)//修改默认对齐数为2
struct S
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//对齐数恢复为默认

struct S2
{
	char c1;
	int i;
	char c2;
};
#include <stddef.h>
int main()
{
	printf("%d\n", offsetof(struct S2, c1));//offsetof 宏，计算成员变量相当于
	//结构体起始地址的偏移值，需引用<stddef.h>
	printf("%d\n", offsetof(struct S2, c1));
	printf("%d\n", offsetof(struct S2, c1));
}


struct S3
{
	int a : 2;//位段
	//先开辟4个字节的空间，然后给a分配2个比特位
	//位段一般是int类型和char类型
	int b : 30;
	int c : 5;
};