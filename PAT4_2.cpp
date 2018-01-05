#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int g[110][110] = { 0 };
int son[110] = {0};
int ceng[110] = {0};

void xiugai(int node,int c,int g[][110],int *ceng)
{
	for (int i = 0; i < 110; i++)
	{
		if (g[node][i] == 0)	break;
			ceng[g[node][i]] = c + 1;
			xiugai(g[node][i],c+1,g,ceng);
	}
}
int main()
{
	int m, n;
	int a, b, c;
	int cengshu = 1;
	cin >> n >> m;
	ceng[1] = 1;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		if (b != 0) {
			son[a] = 1;
			for (int j = 0; j < b; j++)
				scanf("%d", &g[a][j]);
		}
	}
	xiugai(1,ceng[1],g,ceng);
	for (int i = 0; i <= n; i++)
		cengshu = max(cengshu,ceng[i]);
	vector<int> v(cengshu, 0);
	for (int i = 1; i <= n; i++)
	{
		if (son[i] == 0) {
			v[ceng[i]-1] += 1;
		}
	}
	printf("%d", v[0]);
	for (int i = 1; i < cengshu; i++)
		printf(" %d", v[i]);
	return 0;
}