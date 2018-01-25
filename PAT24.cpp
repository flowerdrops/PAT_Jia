#include <iostream>
#include <string>
using namespace std;

bool ispa(string s)
{
	int len = s.length();
	for (int i = 0; i <= len / 2; i++)
	{
		if (s[i] != s[len - 1 - i])
			return false;
	}
	return true;
}

string pa(string s)
{
	string p=s;
	int len = s.length(),t1=0,t2=0;
	for (int i = 0; i < len; i++)
	{
		t2 = t1 + s[i] - '0' + s[len - 1 - i] - '0';
		p[len-1-i] = char(t2 % 10+'0');
		t1 = t2 / 10;
	}
	if (t1 == 1)
		p = "1" + p;
	return p;
}

int main()
{
	string s,p;
	int k,ind=0;
	cin >> s >> k;
	for (ind = 0; ind < k; ind++)
	{
		if (ispa(s)) {
			cout << s << endl << ind;
			return 0;
		}
		s = pa(s);
	}
	cout << s << endl << ind;
	return 0;
}