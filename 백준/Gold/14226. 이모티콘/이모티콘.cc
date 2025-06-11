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

using namespace std;

int n;
bool visited[1005][1005]; //copy, cur

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	queue<pair<pair<int, int>, int>> q; //  copy - cur - cnt
	q.push({ {1,0},0 });
	visited[1][0] = true;

	while (q.size())
	{
		int copy = q.front().first.first;
		int cur = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cur == n)
		{
			cout << cnt;
			break;
		}

		if (cur > 0 && cur < 1001)
		{
			if (visited[cur][cur] == false)
			{
				visited[cur][cur] = true;
				q.push({ {cur,cur},cnt + 1 });
			}
			else if (visited[copy][cur - 1] == false)
			{
				visited[copy][cur - 1] = true;
				q.push({ {copy,cur - 1},cnt + 1 });
			}
		}

		if (copy > 0 && cur + copy < 1001)
		{
			if (visited[copy][cur + copy] == false)
			{
				visited[copy][cur + copy] = true;
				q.push({ {copy,cur + copy},cnt + 1 });
			}
		}
	}

	return 0;
}