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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	long long answer = 0;

	int dice[6];

	for (int i = 0; i < 6; ++i)
		cin >> dice[i];

	if (n == 1)
	{
		int max = 0;
		for (int i = 0; i < 6; ++i)
		{
			answer += dice[i];
			if (max <= dice[i])
				max = dice[i];
		}

		cout << answer - max;
		return 0;
	}

	int m[3];
	m[0] = min(dice[0], dice[5]);
	m[1] = min(dice[1], dice[4]);
	m[2] = min(dice[2], dice[3]);

	sort(m, m + 3);

	int face = m[0];
	int edge = m[0] + m[1];
	int corner = m[0] + m[1] + m[2];

	answer += corner * 4;
	answer += edge * (4 * (n - 2) + 4 * (n - 1));
	answer += face * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));

	cout << answer;
	return 0;
}