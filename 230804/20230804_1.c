

#include <stdio.h>
#include <ctype.h>


int main_1()
{
	char arr1[20] = "NHunbiuUBBIUFYUfu";
	int i = 0;
	while (arr1[i])
	{
		if (isupper(arr1[i]))
		{
			arr1[i] = tolower(arr1[i]);//大写转小写
		}
		printf("%c", arr1[i]);
		i++;
	}
	return 0;
}


#include <string.h>
void mymemcpy(void* a, void* b, int c)
{
	while (c--)
	{
		*((char*)a)++ = *((char*)b)++;//后缀加加优先级高于强制类型转换
	}
}
void mymemmove(void* a, void* b, int c)
{
	if (a < b)
	{
		while (c--)
		{
			*((char*)a)++ = *((char*)b)++;
		}
	}
	else
	{
		while (c--)
		{
			*((char*)a + c) = *((char*)b + c);
		}
	}
}
int main_3()
{
	//内存操作函数
	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr2[20] = { 0 };
	int arr3[10];
	memcpy(arr2, arr1, 20);//拷贝前五个元素
	//memcpy拷贝不重叠的内存(vs里的memcpy也可以拷贝重叠的)

	memmove(arr1 + 2,arr1,20);
	//memmove可以拷贝重叠的内存

	memcpy(arr1,arr2,12);//比较前三个元素

	memset(arr3, 1, 20);
	//将前20个字节都设置为1
	return 0;
}




struct Ni
{
	char q;
	struct Ni* next;//结构体的自引用
};