#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool dig1[10] = { false }, dig2[10] = { false };
int main() {
	string s,p;
	cin >> s;
//	s = "1234567899";
	p = s;
	int k = s.length(),t1=0,t2=0;
	bool res = true;
	for (int i = k-1; i >=0; i--)
	{
		dig1[s[i] - '0'] = true;
		t2 = 2 * (s[i] - '0') + t1;
		p[i] = (char)(t2 % 10 + '0');
		dig2[t2 % 10] = true;
		t1 = t2 / 10;		
	}
	if (t1 == 1)
	{
		p = "1"+p;
		dig2[1] = true;
	}
	for (int i=0;i<10;i++)
		res = res & (dig1[i] == dig2[i]);
	if (res == true)
		printf("Yes\n");
	else
		printf("No\n");
	cout << p;
	return 0;
}