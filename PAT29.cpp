#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(long long int a, long long int b) {
	return a > b;
}

int main() {
	int m,n;
	long long int t;
	vector<long long int> v;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%lld", &t);
		v.push_back(t);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[(m + n) / 2];
	return 0;
}