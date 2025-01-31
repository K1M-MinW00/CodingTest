#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>
using namespace std;

int n, m;
vector<string> v;
string answer;
int answer_cnt = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];


	for (int i = 0; i < m; ++i)
	{
		map<char, int> alpha;

		for (int j = 0; j < n; ++j)
			alpha[v[j][i]]++;

		char c;
		int cnt = 0;

		for (auto cur : alpha)
		{
			if (cur.second > cnt)
			{
				c = cur.first;
				cnt = cur.second;
			}
		}

		answer += c;
		answer_cnt += n - cnt;
	}

	cout << answer << '\n';
	cout << answer_cnt;

	return 0;
}