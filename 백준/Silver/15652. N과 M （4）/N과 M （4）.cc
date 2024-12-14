#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr(10);


void dfs(int num, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= n; ++i)
	{
		arr[k] = i;
		dfs(i, k + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	dfs(1, 0);
	return 0;
}