#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
char ke[4] = { 'C','M','E','A' };

struct stu {
	int ID;
	int chen[4] = {-1};
};

struct dan {
	int ID;
	int n;
};

bool cmp(dan a, dan b)
{
	return a.n > b.n;
}

int zhaozuixiao(int a[])
{
	int res = a[3],ind=3;
	for (int i = 0; i < 3; i++)
	{
		if (res > a[i]) {
			res = a[i];
			ind = i;
		}			
	}
	return ind;
}

int main()
{
	map<int, stu> data1,data2;
	int t_Id,tt;
	scanf("%d %d", &n, &m);
	vector<dan> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t_Id;
		for (int j = 0; j < 3; j++)
			scanf("%d", &data1[t_Id].chen[j]);
		data1[t_Id].chen[3] = (data1[t_Id].chen[0]+ data1[t_Id].chen[1]+ data1[t_Id].chen[2]) / 3;
		p[i].ID = t_Id;	p[i].n = data1[t_Id].chen[0];
	}
	sort(p.begin(), p.end(), cmp);
	data2[p[0].ID].chen[0] = 1;
	int binglie=1;
	for (int i = 1; i < n; i++)
	{
		if (p[i].n==p[i-1].n)
			data2[p[i].ID].chen[0] = binglie;
		else {
			data2[p[i].ID].chen[0] = i + 1;
			binglie = i + 1;
		}
			
	}
		
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
			p[j].n = data1[p[j].ID].chen[i];
		sort(p.begin(), p.end(), cmp);
		binglie = 1;
		data2[p[0].ID].chen[i] = 1;
		for (int j = 1; j < n; j++) {
			if (p[j].n == p[j-1].n)
				data2[p[j].ID].chen[i] = j + 1;
			else {
				data2[p[j].ID].chen[i] = j + 1;
				binglie = j + 1;
			}
		}
			
	}

	for (int i = 0; i < m; i++)
	{
		cin >> t_Id;
		if (data1[t_Id].chen[0] == -1) {
			printf("N/A\n");
			continue;
		}
		tt = zhaozuixiao(data2[t_Id].chen);
		printf("%d %c\n", data2[t_Id].chen[tt], ke[tt]);
	}
	return 0;
}