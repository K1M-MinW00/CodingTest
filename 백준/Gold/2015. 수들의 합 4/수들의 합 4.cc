#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<int> v;
map<int, long long> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	long long k;
	cin >> n >> k;

	v.resize(n + 1);

	int temp = 0;
	long long answer = 0;
	v[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		v[i] += v[i - 1];

		if (v[i] == k)
			++answer;
	}

	for (int i = 1; i <= n; i++)
	{
		answer += m[v[i] - k];
		m[v[i]]++;
	}

	cout << answer;
	return 0;
}