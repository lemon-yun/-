

//字符串 \0
#include <stdio.h>
#include <string.h>

int main_4()
{
	char arr1[] = "abc";//字符串abc实际有四位(不计入字符串长度）\
	                      abc后面隐藏了“\0”，表终止
	char arr2[] = {'a', 'b', 'c'};
	printf("%s\n", arr1);
	printf("%s\n", arr2);//出现乱码，不知道arr2数组c后面还有几位\
	                       解决方法\
                           1.在arr2的中括号里写填>=4的数字限定长度\
	                       用第四个空位代替“\0”（？\
	                       2.在中括号中'c'后面再加一个'\0'

	printf("%d\n", strlen(arr1));//计算字符串长度
	printf("%d\n", strlen(arr2));//结果为随机值

	return 0;
}


//arr 数组
//1、 数据类型 数组名称[长度n] = {元素1,元素2…元素n};
//2、 数据类型 数组名称[] = { 元素1,元素2…元素n };
//3、 数据类型 数组名称[长度n]; \
      数组名称[0] = 元素1; \
      数组名称[1] = 元素2;\
      数组名称[n - 1] = 元素n;
//获取数组元素时： 数组名称[元素所对应下标];
//如：初始化一个数组 int arr[3] = { 1,2,3 }; 那么arr[0]就是元素1。



int main_5()

{

	//第一种形式

	int arrFirst[3] = { 1,2,3 };

	//第二种形式

	int arrSecond[] = { 1,2,3 };

	//第三种形式

	int arrThird[3];

	//给arrThird数组每个元素初始化

	arrThird[0] = 1;

	arrThird[1] = 2;

	arrThird[2] = 3;

	//输出第一个数组中的第二个元素

	printf("%d\n", arrFirst[1]);

	//输出第二个数组中的第二个元素

	printf("%d\n", arrSecond[1]);

	//输出第三个数组中的第二个元素

	printf("%d\n", arrThird[1]);

	return 0;

}



int main_6()

{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'h', 'i', 'j', 'k'};

	//补全代码实现对数组arr的遍历

	//可以采用你自己喜欢的循环结果

	int i;

	for (i = 0; i <= 9; i++)

	{

		printf("%c\n", arr[i]);

	}

	return 0;

}