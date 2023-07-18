

#include <stdio.h>
#include <assert.h>

char * my_strcpy(char* arr1, const char* arr2)//const防止arr2被修改
{
	assert(arr2 != NULL);//断言，运行下看效果
	assert(arr1 != NULL);
	char* a = arr1;
	while (*arr1++ = *arr2++)//当把'\0'赋值过去后，\0的ASCII码值是0，循环结束
	{
		;
	}
	return a;
}

int main_1()
{
	char arr1[10] = "xxxxxxxxxx";
	char arr2[] = "hello";
	printf("%s", my_strcpy(arr1, NULL));
	return 0;
}


//typedef unsigned __int64 size_t
size_t my_strlen(const char* arr1)
{
	assert(arr1 != NULL);
	size_t a = 0;
	while (*arr1++ != '\0')
	{
		a++;
	}
	return a;
}
//strlen源码
//size_t __cdecl strlen (         //__cdecl 函数调用约定
//        const char * str
//        )
//{
//		  const char *eos = str;
//
//		  while( *eos++ );
//
//		  return( eos - str - 1)  //指针-指针，之间的元素个数
//}
int main_2()
{
	char arr1[10] = "";
	printf("%zd", my_strlen(arr1));
	return 0;
}



//计算二进制1的个数
int main_3()
{
	int a = 15;
	int i = 0;
	int c = 0;
	for (i = 0; i < 32; i++)
	{ 
		if (((a >> i) & 1) == 1)
		{
			c++;
		}
	}
	printf("%d", c);
	return 0;
}
//计算二进制1的个数_2(妙极)
int main_4()
{
	int a = 15;
	int c = 0;
	while (a)
	{
		a = a & (a - 1);
		c++;
	}
	//15
	//1111 - n
	//1110 - n-1
	//n & n-1
	//1110 - n
	//1101 - n-1
	//n & n-1
	//1100 - n
	//1011 - n-1
	//n & n-1
	//1000 - n
	//0111 - n-1
	//n & n-1
	//0000 - n
	printf("%d", c);
	return 0;
}


//判断一个数是不是2的n次方
int main_5()
{
	int k = 1024;
	if (k & (k - 1) == 0)
	{
		printf("是");
	}
	//一个数如果是2的n次方，那么二进制数只会有一个1
	//100000000 - k=1024
	//011111111 - k-1= 1023
	//k & (k - 1) = 0
	return 0;
}


//判断两个数的二进制数不同位的个数
int main()
{
	int a = 1999;
	int b = 2299;
	int c = a ^ b;
	int d = 0;
	while (c)
	{
		c = c & (c - 1);
		d++;
	}
	printf("%d", d);
	return 0;
}