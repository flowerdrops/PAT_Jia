#include <iostream>
#include <string>
#include <vector>
using namespace std;

string prt[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
	string t;
	vector<int> v;
	int res = 0, len;
	cin >> t;
	len = t.length();
	for (int i = 0; i < len; i++)
		res += (t[i]) - '0';
	if (res == 0){
		cout << "zero";
		return 0;
		}
	while (res!=0)
	{
		v.push_back(res % 10);
		res = res / 10;
	}
	for (int i = v.size() - 1; i > 0; i--)
	{
		cout << prt[v[i]] << ' ';
	}
	cout << prt[v[0]];
	return 0;
}