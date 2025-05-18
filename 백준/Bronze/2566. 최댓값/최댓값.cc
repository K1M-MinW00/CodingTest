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

#define MAX 9

int v[MAX][MAX];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int answer = 0;
	int x, y;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> v[i][j];

			if (answer <= v[i][j])
			{
				answer = v[i][j];
				x = i, y = j;
			}
		}
	}

	cout << answer << '\n';
	cout << x+1 << ' ' << y+1;

	return 0;
}