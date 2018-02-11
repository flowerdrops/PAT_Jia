#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct per {
	string id;
	string pa;
};
int n;
vector<per> v;
int main() {
	string s1, s2;
	per t;
	bool flag = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		flag = false;
		cin >> t.id >> t.pa;
		for (int j = 0; j < t.pa.length(); j++) {
			if (t.pa[j] == '1') {
				t.pa[j] = '@';
				flag = true;
				continue;
			}
			if (t.pa[j] == '0') {
				t.pa[j] = '%';
				flag = true;
				continue;
			}if (t.pa[j] == 'l') {
				t.pa[j] = 'L';
				flag = true;
				continue;
			}if (t.pa[j] == 'O') {
				t.pa[j] = 'o';
				flag = true;
				continue;
			}
		}
		if (flag)
			v.push_back(t);
	}
	if (v.size() == 0) {
		if (n==1)
			printf("There is %d account and no account is modified", n);
		else
			printf("There are %d accounts and no account is modified", n);
	}
		
	else {
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i].id << " " << v[i].pa << endl;
	}


	return 0;
}