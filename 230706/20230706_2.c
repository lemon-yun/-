

#include <stdio.h>

void text1()//void���ޣ���ʾû�з���ֵ�����ڻ��㲻��
{
	int f = 1;
	printf("%d ", f);
	f++;

}
void text2()
{
	static int h = 1;
	printf("%d ", h);
	h++;

}
//static����̬�ģ����ξֲ��������ı��˱�������������
//ʵ���ϸı��˱����Ĵ洢���ͣ���ջ���ĵ���̬��
//��text2�У�h��������

static int i = 1;//static���ε�ȫ�ֱ���
                 //ʹ��ֻ����������Դ�ļ���ʹ��
                 //ȫ�ֱ������ⲿ���������ڱ����κ�
                 //������ڲ���������

static int add(int j, int k)//���κ�����Դ�ļ��޷��ٵ���
{
	return j + k;
}
int main_3()
{
	int e = 0;
	while (e < 10)
	{
		text1();
		e++;
	}
	printf("\n");
	int g = 0;
	while (g < 10)
	{
		text2();
		g++;

	}



	return 0;
}