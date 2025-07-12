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
#define N 21

int n, answer = 0;
int num[] = { 1,5,10,50 };
bool visited[1001];


void dfs(int cnt, int d, int total)
{
	if (cnt == n)
	{
		if (visited[total])
			return;

		visited[total] = true;
		answer++;

		return;
	}

	for (int i = d; i < 4; ++i)
	{
		dfs(cnt + 1, i, total + num[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	dfs(0, 0, 0);
	cout << answer << '\n';

	return 0;
}