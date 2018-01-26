#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ind {
	string id;
	int score;
	int rank;
	int zu;
	int zu_rank;
};

bool cmp(ind a, ind b) {
	return (a.score==b.score)?(a.id<=b.id):(a.score>b.score);
}

int main()
{
	vector<ind> local, all;
	int n, k,m;
	ind t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		t.zu = i + 1;
		for (int j = 0; j < k; j++)
		{
			cin >> t.id >> t.score;
			local.push_back(t);
		}
		sort(local.begin(), local.end(), cmp);
		m = 1;	local[0].zu_rank = m;
		for (int j = 1; j < k; j++) {
			if (local[j].score != local[j - 1].score) {
				m = j + 1;
			}
			local[j].zu_rank = m;				
		}
		all.insert(all.end(), local.begin(), local.end());
		local.erase(local.begin(), local.end());
	}
	printf("%d\n", all.size());
	sort(all.begin(),all.end(),cmp);
	m = 1;  all[0].rank = m;
	cout << all[0].id << " ";
	printf("%d %d %d\n", m, all[0].zu, all[0].zu_rank);
	for (int i = 1; i < all.size(); i++)
	{
		if (all[i].score != all[i - 1].score)
			m = i + 1;
		all[i].rank = m;
		cout << all[i].id << " ";
		printf("%d %d %d\n", m, all[i].zu, all[i].zu_rank);
	}
	return 0;
}