#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int k;
int v[1025];
vector<vector<int>> answer(15);

void solve(int start, int end, int level)
{
	if (start > end)
		return;
	else if (start == end)
		answer[level].push_back(v[start]);
	
    else
    {
        int mid = (start + end) / 2;
	    answer[level].push_back(v[mid]);
	    solve(start, mid - 1, level + 1);
	    solve(mid + 1, end, level + 1);
    }
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;

	int n = (int)pow(2, k) - 1;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	solve(0, n, 1);

	for (int i = 1; i <= k; ++i)
	{
		for (int j : answer[i])
			cout << j << ' ';
		cout << '\n';
	}
	return 0;
}
