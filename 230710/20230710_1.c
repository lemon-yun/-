

#include <stdio.h>

int main_1()
{
	printf("%d ", printf("%d ", printf("%d ", 33)));
	//�����33 3 2��printf���ص��Ǵ�ӡ����Ļ�ϵ��ַ��������ո�Ҳ�㣩
	//��ֵ�Ż��ӡ�������ȴ�ӡ33���ٴ�ӡ3������ӡ2
	return 0;
}



int main_2()
{
	int a = 10;
	int b = 20;
	int add(int, int);//����Զ��庯�����������·�����Ҫ����������
	//����������һ�����ͷ�ļ�����
	int c = add(a, b);
	printf("%d", c);
	return 0;
}
//�����Ķ���
int add(int x, int y)
{
	return x + y;
}

