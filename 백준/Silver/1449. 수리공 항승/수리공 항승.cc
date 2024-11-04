#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	v.push_back(0);

	int cur = 0, next = 1, cnt = 0;

	while (1)
	{
		if (v[next] - v[cur] <= l - 1)
		{
			next++;
			if (v[next] == 0)
			{
				cnt++;
				break;
			}
		}
		else
		{
			cnt++;
			cur = next;
		}
	}

	cout << cnt;

	return 0;
}