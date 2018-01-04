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
			if (visit[j]==false && dis[j]<minn) //Ѱ�������
			{//�Լ��ж���Щ���Ѿ��߹���
				u = j;  //ÿ�ε��������Ա�֤�ѷ��ʹ��ĵ㣬��Ȼ����С����
				minn = dis[j]; //˳�㻹�����·�������;�Ԯ�ӵ�����
			}
		}
		if (u == -1)break;
		visit[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (visit[v] == false && e[u][v] != inf) { //ûȥ������·
				if (dis[u] + e[u][v] < dis[v]) { // ��ԭ���Ķ�
					dis[v] = dis[u] + e[u][v]; //���¾���
					num[v] = num[u];   //�������·����
					w[v] = w[u]+weight[v];  //������;��Ԯ��
				}
				else if (dis[u] + e[u][v] == dis[v]) { //һ����
					num[v] = num[v] + num[u]; //���·��������
					if (w[u]+weight[v]>w[v])  //�ĸ�������Ԯ�Ӷ�����ĸ�
						w[v] = weight[v] + w[u];
				}
			}
		}
	}
	printf("%d %d", num[c2], w[c2]);
	return 0;
}