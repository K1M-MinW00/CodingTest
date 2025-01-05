#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> a;
vector<int> visited;

vector<vector<int>> answer;

void solve(vector<int> v)
{
	if (v.size() == m)
	{
		answer.push_back(v);
		return;
	}

	for (int i = 0; i < n; ++i)
	{

		v.push_back(a[i]);
		solve(v);
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
	visited.resize(n, false);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());

	vector<int> temp;

	for (int i = 0; i < n; ++i)
	{
		temp.push_back(a[i]);
		solve(temp);
		temp.pop_back();
	}

	sort(answer.begin(), answer.end());
	temp.clear();

	for (auto v : answer)
	{
		if (temp == v)
			continue;
		for (int i = 0; i < m; ++i)
			cout << v[i] << ' ';
		cout << '\n';

		temp = v;
	}

	return 0;
}
