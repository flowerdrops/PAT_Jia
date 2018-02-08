#include <iostream>
using namespace std;

int p[100000] = { -1 };
bool c[100000] = { false };

int main() {
	int a, b, n, t1, t2;
	char t;
	scanf("%d %d %d", &a, &b, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &t1, &t, &t2);
		p[t1] = t2;
	}
	while (p[a] != -1) {
		c[a] = true;
		a = p[a];
	}
	c[a] = true;
	while (p[b] != -1) {
		if (c[b] == true) {
			printf("%05d", b);
			return 0;
		}
		b = p[b];
	}
	if (c[b] == true)
		printf("%05d", b);
	else
		cout << "-1";
	return 0;
}