

#define _CRT_SECURE_NO_WARNINGS 1  //���scanf��44��45�У�
#include <stdio.h>//����ͷ�ļ�����

int ABC = 3;//ȫ�ֱ������ڴ�������

extern int EFD;//�������������ø���Դ�ļ��ı�������

int main_1()//һ�����̻������̶�ֻ����һ��main��������main_1����ִ�У���
{
	printf("hello world\n");//   \n�Ƿ��е���˼
	printf("%d\n", ABC);//��ӡһ������ ���� %d��%ld��%Ld�����ͣ�%hd�����ͣ�
	printf("%d\n", EFD);
	printf("%d\n", 100);


	printf("%d\n", sizeof(char));//sizeof ���� �������ͻ������ռ�ռ�Ĵ�С
	printf("%d\n", sizeof(char));//�ַ���������
	printf("%d\n", sizeof(short));//������
	printf("%d\n", sizeof(int));//����
	printf("%d\n", sizeof(long));//������
	printf("%d\n", sizeof(long long));//����������
	printf("%d\n", sizeof(float));//�����ȸ�����
	printf("%d\n", sizeof(double));//˫���ȸ�����


	int age = 16;//�ֲ��������ڴ�������
	age = age + 1;
	printf("���� = %d\n", age);
	float weight = 62.0;
	double weight_1 = 62.0;
	printf("���� = %.9f\n", weight);//�����������float��%f
	                             //��%.nf ����n��ʾ��ȷ��С��λ��nλ��
	printf("���� = %lf\n", weight_1);//�����������double��%lf
	

	int a = 0;
	int b = 0;
	int c = 0;
	printf("����������������ע��������֮���ÿո����\n");
	scanf("%d %d", &a, &b);//scanf ���� ���뺯���������ڳ�������������
	//ע��          &
	//ֱ��ʹ��scanf����ִ�����Ҫ�����д���������棨��һ�У�����
	//��#define _CRT_SECURE_NO_WARNINGS 1��
	//Ҳ����ʹ�á�scanf_s�����桰scanf�������ǣ��˺�������VS�ṩ�ģ�����C���Եģ�
	c = a + b;
	printf("���������Ϊ%d %d,���Ϊ%d\n",a, b, c);//һһ��Ӧ


	char gameover = 'g';//ע�ⵥ����
	printf("%c\n", gameover);//���һ���ַ�%c
	printf("%c\n", 'h');
	char *victory = "gg";//ע���Ǻź�˫����
	printf("%s\n", victory);//���һ���ַ���%s

	
	


	getchar();//�����������
	return 0;
}


