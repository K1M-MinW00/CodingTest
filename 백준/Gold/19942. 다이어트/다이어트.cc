#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int n, mp, mf, ms, mv;
int answer = INT_MAX;
map<int, vector<vector<int>>> m;

int v[15][5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; ++i)
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];

	int b, c, d, e, sum;
	for (int i = 1; i < (1 << n); ++i)
	{
		b = c = d = e = sum = 0;
		vector<int> temp;

		for (int j = 0; j < n; ++j)
		{
			if ((i & (1 << j)))
			{
				temp.push_back(j + 1);
				b += v[j][0];
				c += v[j][1];
				d += v[j][2];
				e += v[j][3];
				sum += v[j][4];
			}
		}

		if (b >= mp && c >= mf && d >= ms && e >= mv)
		{
			if (answer >= sum)
			{
				answer = sum;
				m[answer].push_back(temp);
			}
		}
	}

	if (answer == INT_MAX)
		cout << -1;

	else
	{
		cout << answer << '\n';
		sort(m[answer].begin(), m[answer].end());

		for (int a : m[answer][0])
			cout << a << ' ';
	}

	return 0;
}