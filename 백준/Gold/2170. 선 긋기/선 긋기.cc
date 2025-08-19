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
	cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	int start, end, next_i;
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		start = v[i].first;
		end = v[i].second;
		next_i = -1;

		for (int j = i + 1; j < n; ++j)
		{
			if (v[j].first <= end)
			{
				end = max(end, v[j].second);
				next_i = j;
			}
			else
			{
				break;
			}
		}

		if (next_i != -1)
		{
			i = next_i;
		}

		answer += (end - start);
		// cout << start << " ~ " << end << " : " << end - start << ", sum = " << answer << '\n';
	}

	cout << answer;

	return 0;
}