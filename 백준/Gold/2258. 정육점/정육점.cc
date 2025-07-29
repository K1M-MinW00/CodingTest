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

int n, m;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first > b.first;

	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		int w, c;
		cin >> w >> c;

		v.push_back({ w,c });
	}

	sort(v.begin(), v.end(), cmp);


	int sum = 0, cost = 0;
	int answer = INT_MAX;
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i].first;

		if (i != 0 && v[i - 1].second == v[i].second)
		{
			cost += v[i].second;
		}
		else
		{
			cost = v[i].second;
		}

		if (sum >= m)
		{
			answer = min(answer, cost);
			flag = true;
		}
	}

	if (!flag)
		cout << -1;
	else
		cout << answer;

	return 0;
}