#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> S(20, 0);
vector<bool> check(2000001, false);

void dfs(int i, int sum)
{
	if (i == n) {
		check[sum] = true;
		return;
	}

	dfs(i + 1, sum + S[i]);
	dfs(i + 1, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> S[i];

	dfs(0, 0);

	int i = 0;
	while (1)
	{
		if (!check[i])
		{
			cout << i;
			break;
		}
		++i;
	}
	return 0;
}