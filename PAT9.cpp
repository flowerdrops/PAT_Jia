#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct wei {
	int ind;
	float xishu;
};
float c[2001] = { 0.0 };
bool cflag[2001] = { false };

int main()
{
	int n1, n2;
	vector<wei> a;
	wei tmp;
	scanf("%d", &n1);

	for (int i = 0; i < n1; i++)
	{
		cin >> tmp.ind >> tmp.xishu;
		a.push_back(tmp);
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		cin >> tmp.ind >> tmp.xishu;
		for (int j = 0; j < n1; j++)
		{
			c[tmp.ind + a[j].ind] += tmp.xishu*a[j].xishu;
			cflag[tmp.ind + a[j].ind] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (c[i] != 0.0)
			count++;
	}
	cout << count;
	for (int i = 2001; i >= 0; i--)
	{
		if (c[i]!= 0.0)
			printf(" %d %.1f", i, c[i]);
	}
	return 0;
}