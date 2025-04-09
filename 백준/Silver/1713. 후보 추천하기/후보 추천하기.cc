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

using namespace std;

int n;
vector<pair<int, int>> v;

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

void v_erase()
{
	int min_cnt = INT_MAX;

	for (int i = 0; i < v.size(); ++i)
		min_cnt = min(min_cnt, v[i].second);

	for (int i = 0; i < v.size(); ++i)
	{
		if (min_cnt == v[i].second)
		{
			v.erase(v.begin() + i);
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int k, num;

	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> num;
		bool flag = false;

		for (int i = 0; i < v.size(); ++i)
		{
			if (num == v[i].first)
			{
				flag = true;
				v[i].second++;
				break;
			}
		}

		if (flag == false)
		{
			if (v.size() < n)
				v.push_back({ num,1 });
			else if (v.size() == n)
			{
				v_erase();
				v.push_back({ num,1 });
			}
		}
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].first << ' ';
	return 0;
}