

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main_1()
{
	//C++����ӡ�ַ���
	string str = "Hello World!";//������ <string>
	cout << str << endl;

	return 0;
}

int main_2()
{
	//C++�������
	srand((unsigned int)time(NULL));//������ <ctime>
	int ret = rand();

	return 0;
}