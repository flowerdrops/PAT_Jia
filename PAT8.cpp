#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	int now=0, go, t=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &go);
		if (go > now)
		{
			t = t + 6 * (go - now) + 5;
			now = go;
			continue;
		}
		if (go < now) {
			t = t + 4 * (now-go) + 5;
			now = go;
			continue;
		}
		if (go == now) {
			t = t + 5;
			continue;
		}
	}
	cout << t;
	return 0;
}