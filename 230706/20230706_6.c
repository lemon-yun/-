

#include <stdio.h>

struct stu
{
	char name[30];//��Ա����
	int age;
};
int main_8()
{
	struct stu z = {"����", 17};//�ṹ��Ĵ����ͳ�ʼ��
	printf("%s, %d", z.name, z.age);//�ṹ����.��Ա����
	struct stu* pz = &z;
	printf("%s, %d", pz->name, pz->age);//->��������һ���÷�
	return 0;
}