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
#include <unordered_map>

using namespace std;

int v[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;

		for (int x = a; x < a + 10; ++x)
		{
			for (int y = b; y < b + 10; ++y)
			{
				v[x][y] = 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			if (v[i][j] == 1)
				answer++;
		}
	}

	cout << answer;
	return 0;
}