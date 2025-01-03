#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n, a, b;
string answer;
bool visited[10000];
char oper[4] = { 'D','S','L','R' };
int cal[4];

void op(int cur)
{
	cal[0] = (cur * 2) % 10000;

	if (cur == 0)
		cal[1] = 9999;
	else
		cal[1] = cur - 1;

	int d1 = cur / 1000;
	cal[2] = (cur * 10) % 10000 + d1;

	int d4 = cur % 10;
	cal[3] = (cur / 10) + d4 * 1000;
}

void solve()
{
	queue<pair<int, string>> q;
	visited[a] = true;

	q.push({ a,"" });

	while (q.size())
	{
		int cur = q.front().first;
		string str = q.front().second;
		q.pop();

		if (cur == b)
		{
			answer = str;
			break;
		}

		op(cur);

		for (int i = 0; i < 4; ++i)
		{
			int next = cal[i];
			if (visited[next])
				continue;

			visited[next] = true;
			q.push({ next,str + oper[i] });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	while (n--)
	{
		fill(visited, visited + 10000, false);
		cin >> a >> b;

		solve();

		cout << answer << '\n';
	}
	return 0;
}