#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, root, r;
vector<int> adj[51];

int dfs(int parent)
{
	int ret = 0;
	int child_cnt = 0;

	for (int child : adj[parent])
	{
		if (child == r)
			continue;

		ret += dfs(child);
		child_cnt++;
	}
	if (child_cnt == 0)
		return 1;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;

		if (temp == -1)
			root = i;
		else
			adj[temp].push_back(i);
	}

	cin >> r;

	if (r == root)
		cout << 0;
	else
		cout << dfs(root);

	return 0;
}