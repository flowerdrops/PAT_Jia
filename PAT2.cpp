#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n1, n2, a,cnt = 0;
	float arr[1001] = { 0.0 },b;
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++)
	{
		scanf("%d %f",&a,&b);
		arr[a] = b;
	}
	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		scanf("%d %f", &a, &b);
		arr[a] += b;
	}
	for (int i = 0; i < 1001; i++)
	{
		if (arr[i] != 0.0)
			cnt++;
	}
	cout << cnt;
	for (int i = 1000; i >= 0; i--)
	{
		if (arr[i] != 0.0)
			printf(" %d %.1f", i, arr[i]);
	}
	return 0;
}