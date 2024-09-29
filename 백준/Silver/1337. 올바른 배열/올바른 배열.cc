#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int answer = 5;

	for (int i = 0; i < n; ++i)
	{
		vector<int> temp(5);

		for (int j = 0; j < 5; ++j)
			temp[j] = v[i] + j;

		int cnt = 0;

		int idx = i;
		for (int j = 0; j < 5; ++j)
		{
			if (idx < n && v[idx] == temp[j])
			{
				cnt++;
				idx++;
			}
		}
		answer = min(5 - cnt, answer);
	}

	cout << answer;

	return 0;
}