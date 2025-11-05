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
#include <tuple>

using namespace std;

int n;
int v[101];
bool visited[101];

set<int> s;

void dfs(int idx)
{
	memset(visited, 0, sizeof(visited));

	stack<int> st;
	st.push(idx);

	vector<int> temp;
	temp.push_back(idx);
	bool cycle = false;

	while (st.size())
	{
		int cur = st.top();
		st.pop();

		visited[cur] = true;

		int next = v[cur];

		if (next == idx)
		{
			temp.push_back(next);
			cycle = true;
			break;
		}

		if (visited[next] == false)
		{
			temp.push_back(next);
			st.push(next);
		}
	}

	if (cycle)
	{
		for (int i : temp)
			s.insert(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = 1; i <= n; ++i)
	{
		dfs(i);
	}

	cout << s.size() << '\n';

	for (int i : s)
		cout << i << '\n';

	return 0;
}