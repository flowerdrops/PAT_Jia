#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a, b, tmp;
	int prt[3] = { 0,0,0 };
	bool flag = false;
	cin >> a >> b;
	tmp = a + b;
	if (tmp<0)
	{
		cout << "-";
		tmp = -tmp;
	}
	if (tmp == 0)
	{
		cout << 0 << endl;
		return 0;
	}
		
	for (int i = 0; i < 3; i++)
	{
		prt[2 - i] = tmp % 1000;
		tmp = tmp / 1000;
	}
	for (int i = 0; i < 2; i++)
	{

		if (flag)
			printf("%03d,", prt[i]);
		else
		{
			if (prt[i] != 0)
			{
				flag = true;
				printf("%d,", prt[i]);
			}

		}
	}
	if (flag)
		printf("%03d\n", prt[2]);
	else
		printf("%d\n", prt[2]);
	return 0;
}