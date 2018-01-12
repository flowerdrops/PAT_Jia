#include <iostream>
#include <algorithm>
using namespace std;

float g[3][3];
char p[3] = {'W','T','L'};

int findmax(float g[])
{
	int ind = 0, zuida = g[0];
	if (g[1] >= zuida)
	{
		ind = 1;
		zuida = g[1];
	}
	if (g[2] >= zuida) {
		ind = 2;
		zuida = g[2];
	}
	return ind;
}


int main()
{
	int a[3] = {1};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cin >> g[i][j];
		a[i] = findmax(g[i]);
		cout << p[a[i]] << " ";
	}
	printf("%.2f", 2*(0.65*g[0][a[0]] * g[1][a[1]] * g[2][a[2]] - 1));
	return 0;
}