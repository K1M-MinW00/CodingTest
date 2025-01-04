#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
vector<int> a;
vector<bool> visited;
vector<vector<int>> answer;

void print(vector<int> v)
{
	for (int i = 0; i < m; ++i)
		cout << v[i] << ' ';
	cout << '\n';

	return;
}

void solve(vector<int> v)
{
	if (v.size() == m)
	{
		answer.push_back(v);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		v.push_back(a[i]);
		solve(v);
		visited[i] = false;
		v.pop_back();
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	a.resize(n);
	visited.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector<int> v;
	solve(v);


	vector<int> before;
	sort(answer.begin(), answer.end());
	for (auto v : answer)
	{
		if (before == v)
			continue;

		print(v);

		before = v;
	}
	return 0;
}
