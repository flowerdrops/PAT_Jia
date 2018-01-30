#include <iostream>
#include <string>
using namespace std;

int d[3] = { 0 };
string s="#000000";

int main() {
	for (int i = 0; i < 3; i++) {
		scanf("%d", &d[i]);
		s[2 * i + 2] = (d[i] % 13 < 10) ? (d[i] % 13 + '0') : (d[i] % 13 - 10 + 'A');
		s[2 * i + 1] = (d[i] / 13 < 10) ? (d[i] / 13 + '0') : (d[i] / 13 - 10 + 'A');
	}
	cout << s;
	return 0;
}