#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;
int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for (int i = 0; i < n; i++)
		scanf("%d", &weight[i]);
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	dis[c1] = 0;
	w[c1] = weight[c1];
	num[c1] = 1;
	int u = -1, minn = inf;
	for (int i = 0; i < n; i++) {
		u = -1; minn = inf;
		for (int j = 0; j < n; j++) {
			if (visit[j]==false && dis[j]<minn) //寻找最初点
			{//以及判断那些点已经走过了
				u = j;  //每次迭代都可以保证已访问过的点，必然是最小距离
				minn = dis[j]; //顺便还有最短路的数量和救援队的数量
			}
		}
		if (u == -1)break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (visit[v] == false && e[u][v] != inf) { //没去过又有路
				if (dis[u] + e[u][v] < dis[v]) { // 比原来的短
					dis[v] = dis[u] + e[u][v]; //更新距离
					num[v] = num[u];   //延续最短路数量
					w[v] = w[u]+weight[v];  //加入沿途救援队
				}
				else if (dis[u] + e[u][v] == dis[v]) { //一样长
					num[v] = num[v] + num[u]; //最短路数量增加
					if (w[u]+weight[v]>w[v])  //哪个方案救援队多就用哪个
						w[v] = weight[v] + w[u];
				}
			}
		}
	}
	printf("%d %d", num[c2], w[c2]);
	return 0;
}