#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

int n, k, cnt = 0;
vector<int> v;
bool answer = false;

void solve(int cur)
{
	if (cur > n)
	{
		v.pop_back();
		return;
	}

	if (cur == n)
	{
		cnt++;

		if (cnt == k)
		{
			answer = true;

			for (int i = 0; i < v.size(); ++i)
			{
				cout << v[i];
				if (i != v.size() - 1)
					cout << "+";
			}
		}
		v.pop_back();
		return;
	}

	v.emplace_back(1);
	solve(cur + 1);

	v.emplace_back(2);
	solve(cur + 2);

	v.emplace_back(3);
	solve(cur + 3);

	if (v.size() > 0)
		v.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	solve(0);

	if (!answer)
		cout << -1;

	return 0;
}