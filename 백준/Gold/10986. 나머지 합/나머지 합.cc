#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> v(m);

	long long  sum = 0, temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
		v[sum % m]++;
	}

	long long answer = 0;
	for (int i = 0; i < m; ++i)
		answer += v[i] * (v[i] - 1) / 2;

	cout << answer + v[0];
	return 0;
}