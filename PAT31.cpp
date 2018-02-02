#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int n1 = 1, n2 = 3;
	while (n1 <= n2) {
		if (n2<3 || n2>n)
			break;
		n1++;
		n2 = n + 2 - n1 - n1;
		
	}
	n1--;
	n2 = n + 2 - n1 - n1;
	for (int i = 0; i < n1-1; i++) {
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++) {
			cout << " ";
		}
		cout << s[n - 1 - i] << endl;
	}
	for (int i = 0; i < n2; i++)
		cout << s[n1-1+i];
	return 0;
}