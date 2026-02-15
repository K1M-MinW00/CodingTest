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
#include <sstream>
#include <deque>

using namespace std;

int n;
vector<int> v[100001];
vector<int> order;

int pos[100001];
bool check[100001];


bool compare(int& a, int& b)
{
	return pos[a] < pos[b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	order.resize(n);

	int a, b;
	for (int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> order[i];
		pos[order[i]] = i;
	}

	if (order[0] != 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; ++i)
	{
		sort(v[i].begin(), v[i].end(), compare);
	}

	stack<pair<int, int>> st;
	vector<int> result;

	st.push({ 1,0 });
	result.push_back(1);
	check[1] = true;

	while (!st.empty())
	{
		int cur = st.top().first;
		int& idx = st.top().second;

		if (idx == v[cur].size())
		{
			st.pop();
			continue;
		}

		int next = v[cur][idx];
		idx++;

		if (!check[next])
		{
			check[next] = true;
			st.push({ next,0 });
			result.push_back(next);
		}
	}

	if (result == order)
		cout << 1;

	else
		cout << 0;

	return 0;
}