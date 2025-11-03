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

#define N 201

int sender[] = { 0,0,1,1,2,2 };
int receiver[] = { 1,2,0,2,0,1 };

bool visited[N][N];
vector<int> answer;

int cur[3];

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	visited[0][0] = true;
	answer.push_back(cur[2]);

	while (q.size())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = cur[2] - a - b;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int next[] = { a,b,c };
			next[receiver[i]] += next[sender[i]];
			next[sender[i]] = 0;

			if (next[receiver[i]] > cur[receiver[i]])
			{
				next[sender[i]] = next[receiver[i]] - cur[receiver[i]];
				next[receiver[i]] = cur[receiver[i]];
			}

			if (!visited[next[0]][next[1]])
			{
				visited[next[0]][next[1]] = true;
				q.push({ next[0],next[1] });

				if (next[0] == 0)
				{
					answer.push_back(next[2]);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> cur[0] >> cur[1] >> cur[2];

	bfs();

	sort(answer.begin(), answer.end());

	for (int i : answer)
		cout << i << ' ';

	return 0;
}