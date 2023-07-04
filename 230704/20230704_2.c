

//常量有关

#define Z 1000//定义Z为常量1000，后续更改（如 Z = 100;），则会报错
#include <stdio.h>
int main_2()
{
	const int ok = 3;//const修饰后，ok变为常变量（常变量属于变量）
	//如果后面重新定义ok（如 ok = 4;），则会报错
#define M 100//大括号里面定义也行

	printf("%d\n", Z);
	printf("%d\n", ok);
	printf("%d\n", M);
	return 0;
}



//枚举常量
//SEX之后可以去的值只能是大括号里面的
enum SEX
{
	male = 3,//默认此时male的值为0，female为1
	     //可在此进行赋值（如 male = 1,），那么female为2
	female,

};//注意分号

int main_3()
{
	enum SEX s = male;//定义s，如果是 enum SEX s = maleee; 则会报错
	                  //另外， int s = male; 的结果是一样的，但不知道\
	                    两种定义是否相同
		printf("%d\n", s);
		printf("%d\n", female);//因为male赋值为3，则此处输出为4
	return 0;
}

