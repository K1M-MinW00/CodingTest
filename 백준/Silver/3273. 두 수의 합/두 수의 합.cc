#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int target;
	cin >> target;

	int cnt = 0;
	int s = 0, e = n - 1;

	while (s < e)
	{
		if (v[s] + v[e] == target)
		{
			++cnt;
			++s;
			--e;
		}
		else if (v[s] + v[e] < target)
			++s;
		else
			--e;
	}

	cout << cnt;

	return 0;
}