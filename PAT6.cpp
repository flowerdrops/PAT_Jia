#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct person {
	string ID;
	int lai;
	int zou;
};

bool cmp1(person a,person b)
{
	return a.lai < b.lai;
}

bool cmp2(person a, person b)
{
	return a.zou > b.zou;
}

int main()
{
	int n;
	cin >> n;
	vector<person> v(n);
	int a, b, c;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].ID;
		scanf("%2d:%2d:%2d", &a, &b, &c);
		v[i].lai = a * 3600 + b * 60 + c;
		scanf("%2d:%2d:%2d", &a, &b, &c);
		v[i].zou = a * 3600 + b * 60 + c;
	}
	sort(v.begin(), v.end(), cmp1);
	cout<<v[0].ID<<" ";
	sort(v.begin(), v.end(), cmp2);
	cout << v[0].ID;
	return 0;
}