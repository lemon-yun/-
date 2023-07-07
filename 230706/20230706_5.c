

#include <stdio.h>
//指针

int main_6()
{
	int q = 1;//q在内存中要分配四个字节的空间
	printf("%p\n", &q);// %p用于打印地址，注意 &取地址操作符（？
	                 //我们获取的地址是q的分配的第一个字节的地址
	int* pq = &q;//pq是用来存放地址的，在C语言中pq\
	               被称为指针变量
	// * 说明pq是指针变量
	//int说明pq执行的对象是int类型的

	char r = 'R';
	char* pr = &r;


	return 0;
}


int main_7()
{
	int s = 1;
	int* ps;
	ps = &s;

	*ps = 2;
	// * 解引用操作，*ps就是通过ps里面的地址，找到s（改变s？
	printf("%d\n", s);
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(int*));

	//指针就是地址
	//不同类型指针的大小是相同的，取决于地址的存储需要多大位置
	//32位为4字节，64位为8字节
	//32位地址是32个0或1组成的序列，32个比特即4字节
	//64位地址是64个0或1组成的序列，64个比特即8字节
	return 0;
}

