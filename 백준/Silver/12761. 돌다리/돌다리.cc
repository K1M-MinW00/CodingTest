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
int a, b, n, m;
bool visited[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> n >> m;

	queue<pair<int, int>> q;
	q.push({ n,0 });

	while (q.size())
	{
		int cur = q.front().first;
		int cnt = q.front().second;

		q.pop();

		if (cur == m)
		{
			cout << cnt << '\n';
			break;
		}

		int next[] = { cur + 1,cur - 1,cur + a,cur - a,cur + b,cur - b,cur * a,cur * b };

		for (int i = 0; i < 8; ++i)
		{
			if (next[i] >= 0 && next[i] <= 100000)
			{
				if (!visited[next[i]])
				{
					visited[next[i]] = true;
					q.push({ next[i],cnt + 1 });
				}
			}
		}
	}

	return 0;
}