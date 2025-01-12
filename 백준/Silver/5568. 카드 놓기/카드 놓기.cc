#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define MAX 1002
using namespace std;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
int n, k;

vector<string> v;
vector<bool> visited;
set<string> answer;

void solve(int depth, string temp)
{
	if (depth == k)
	{
		answer.insert(temp);
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		solve(depth + 1, temp + v[i]);
		visited[i] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	v.resize(n);
	visited.resize(n);


	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	solve(0, "");

	cout << answer.size();
	return 0;
}
