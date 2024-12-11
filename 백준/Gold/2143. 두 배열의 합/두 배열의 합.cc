#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	int n, m;
	cin >> n;

	map<long long, long long> mp;

	vector<long long> a(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i] += a[i - 1];

		for (int j = 0; j < i; ++j)
		{
			long long temp = a[i] - a[j];
			mp[t - temp]++;
		}
	}

	cin >> m;
	vector<long long> b(m + 1);
	
	long long answer = 0;

	for (int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		b[i] += b[i - 1];

		for (int j = 0; j < i; ++j)
		{
			long long temp = b[i] - b[j];
			answer += mp[temp];
		}
	}

	cout << answer;
	return 0;
}