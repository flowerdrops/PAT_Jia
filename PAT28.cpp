#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu{
	string name;
	int ID;
	int grad;
};

bool cmp1(stu a, stu b) {
	return a.ID < b.ID;
}
bool cmp2(stu a, stu b) {
	return (a.name == b.name)?(a.ID<b.ID):(a.name < b.name);
}
bool cmp3(stu a, stu b) {
	return (a.grad == b.grad)?(a.ID<b.ID):(a.grad < b.grad);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	stu tmp;
	vector<stu> v;
	for (int i = 0; i < n; i++)
	{
		//scanf("%d %s %d",&tmp.ID,&tmp.name,&tmp.grad);
		scanf("%d", &tmp.ID);
		cin >> tmp.name;
		scanf("%d", &tmp.grad);
		v.push_back(tmp);
	}
	if (k==1)
		sort(v.begin(), v.end(), cmp1);
	if (k==2)
		sort(v.begin(), v.end(), cmp2);
	if (k==3)
		sort(v.begin(), v.end(), cmp3);
	for (int i = 0; i < n; i++) {
		printf("%06d ",v[i].ID);
		cout << v[i].name;
		printf(" %d\n", v[i].grad);
	}	
	return 0;
}