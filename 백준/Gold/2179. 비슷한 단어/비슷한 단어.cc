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
#include <unordered_set>
#include <bitset>
#include <tuple>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);
	map<string, vector<int>> m;

	int max_len = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];

		for (int j = 0; j <= v[i].length(); ++j)
		{
			string prefix = v[i].substr(0, j);

			m[prefix].push_back(i);

			if (m[prefix].size() >= 2 && prefix.length() > max_len)
				max_len = prefix.length();
		}
	}

	int idx = n;
	string answer;
	for (auto element : m)
	{
		string _pre = element.first;
		vector<int> temp = element.second;

		if (temp.size() >= 2 && _pre.length() == max_len)
		{
			if (temp[0] < idx)
			{
				idx = temp[0];
				answer = _pre;
			}
		}
	}

	int idx1 = m[answer][0];
	int idx2 = m[answer][1];

	cout << v[idx1] << '\n';
	cout << v[idx2];

	return 0;
}