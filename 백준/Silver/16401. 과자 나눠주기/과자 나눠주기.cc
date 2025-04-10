#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int m, n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;

	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int s = 1, e = v.back(), mid;
	int answer = 0;

	while (s <= e)
	{
		mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += (v[i] / mid);

		if (cnt < m)
			e = mid - 1;
		else
		{
			s = mid + 1;
			answer = max(answer, mid);
		}
	}

	cout << answer;
	return 0;
}