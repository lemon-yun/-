

#include <stdio.h>

struct stu
{
	char name[30];//成员变量
	int age;
};
int main_8()
{
	struct stu z = {"张三", 17};//结构体的创建和初始化
	printf("%s, %d", z.name, z.age);//结构体名.成员变量
	struct stu* pz = &z;
	printf("%s, %d", pz->name, pz->age);//->操作符的一个用法
	return 0;
}