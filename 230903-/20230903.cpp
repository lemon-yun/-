

#include <iostream>
using namespace std;

int main_1()
{
	cout << "Hello World!";
	return 0;
}

int main_2()
{
	int x, y, z;
	cin >> x >> y;
	if (x > y) z = x;
	else z = y;
	cout << "较大值为 :"<<' '<< z << endl;
	return 0;
}



long pow(int x, int n)
{

	int i = 1;
	long p = 1;
	while (i <= n)
	{
		p = p * x;
		i = i + 1;
	}
	return p;
}
int main()
{
	int x, n;
	cin >> x >> n;
	cout << pow(x, n) << endl;

	return 0;
}