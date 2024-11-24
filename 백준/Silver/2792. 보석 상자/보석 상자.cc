#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

int bin()
{
	int left = 1, right = v[m - 1], mid;
	int answer = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		long long cnt = 0;

		for (int i = 0; i < m; ++i)
		{
			cnt += (v[i] / mid);
			if (v[i] % mid != 0)cnt++;
		}

		if (cnt <= n)
		{
			right = mid - 1;
			answer = mid;
		}
		else
			left = mid + 1;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	v.resize(m);

	for (int i = 0; i < m; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	cout << bin();

	return 0;
}