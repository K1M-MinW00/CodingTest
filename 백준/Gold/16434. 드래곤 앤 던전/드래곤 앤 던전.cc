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
#include <bitset>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	long long atk;

	cin >> n >> atk;

	long long t, a, h;
	long long curHP = 0, answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> t >> a >> h;

		if (t == 1)
		{
			h -= atk;

			if (h > 0)
			{
				if (h % atk == 0)
					curHP += a * h / atk;
				else
					curHP += a * (h / atk + 1);
			}
		}
		else
		{
			curHP = max(curHP - h, 0LL);
			atk += a;
		}
		answer = max(answer, curHP);
	}

	cout << answer + 1;
	return 0;
}