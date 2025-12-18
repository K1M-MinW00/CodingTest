#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n, m;
int v[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	long long answer = 0;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; ++j)
		{
			v[i][j] = str[j] - '0';

			if (v[i][j] == 1 && i > 0 && j > 0)
			{
				v[i][j] = min(v[i - 1][j - 1], min(v[i - 1][j], v[i][j - 1])) + v[i][j];
			}

			if (answer < v[i][j])
				answer = v[i][j];
		}
	}

	cout << answer * answer;

	return 0;
}