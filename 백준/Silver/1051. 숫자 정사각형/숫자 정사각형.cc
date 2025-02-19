#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <cmath>

using namespace std;

int n, m;
int v[51][51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	string line;

	for (int i = 0; i < n; ++i)
	{
		cin >> line;
		for (int j = 0; j < m; ++j)
			v[i][j] = line[j] - '0';
	}


	int answer = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int cnt = 0;
			for (int k = 1; k <= min(m, n); ++k)
			{
				if (i + k >= n || j + k >= m)
					break;
				if (v[i][j] == v[i][j + k] && v[i][j] == v[i + k][j] && v[i][j] == v[i + k][j + k])
				{
					if (cnt < k)
						cnt = k;
				}
			}
			if (cnt + 1 > answer)
				answer = cnt + 1;
		}
	}

	cout << answer * answer;
	return 0;
}