

//�����й�

#define Z 1000//����ZΪ����1000���������ģ��� Z = 100;������ᱨ��
#include <stdio.h>
int main_2()
{
	const int ok = 3;//const���κ�ok��Ϊ�����������������ڱ�����
	//����������¶���ok���� ok = 4;������ᱨ��
#define M 100//���������涨��Ҳ��

	printf("%d\n", Z);
	printf("%d\n", ok);
	printf("%d\n", M);
	return 0;
}



//ö�ٳ���
//SEX֮�����ȥ��ֵֻ���Ǵ����������
enum SEX
{
	male = 3,//Ĭ�ϴ�ʱmale��ֵΪ0��femaleΪ1
	     //���ڴ˽��и�ֵ���� male = 1,������ôfemaleΪ2
	female,

};//ע��ֺ�

int main_3()
{
	enum SEX s = male;//����s������� enum SEX s = maleee; ��ᱨ��
	                  //���⣬ int s = male; �Ľ����һ���ģ�����֪��\
	                    ���ֶ����Ƿ���ͬ
		printf("%d\n", s);
		printf("%d\n", female);//��Ϊmale��ֵΪ3����˴����Ϊ4
	return 0;
}

