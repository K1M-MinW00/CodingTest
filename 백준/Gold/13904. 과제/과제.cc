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


int arr[1001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), cmp);

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		int end = v[i].first;
		int score = v[i].second;

		for (int j = end; j > 0; --j)
		{
			if (arr[j] == 0)
			{
				arr[j] = v[j].first;
				answer += score;
				break;
			}
		}
	}

	cout << answer;

	return 0;
}