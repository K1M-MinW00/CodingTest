#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int cx, cy, r;

bool isInCircle(int x, int y)
{
	int dSquare = (r * r) - ((x - cx) * (x - cx) + (y - cy) * (y - cy));

	return dSquare > 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	int x1, x2, y1, y2, n, answer;

	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		answer = 0;

		for (int i = 0; i < n; ++i)
		{
			cin >> cx >> cy >> r;

			answer += (isInCircle(x1, y1) != (isInCircle(x2, y2)));
		}

		cout << answer << '\n';
	}
	return 0;
}