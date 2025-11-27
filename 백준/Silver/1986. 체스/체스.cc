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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

int n, m;
int v[1001][1001]; // 0 : empty, 1 : queen, 2 : knight, 3 : pawn ,4 : occupied
bool visited[1001][1001];
vector<pair<int, int>> queen, knight;

int mx_q[] = { 1,1,1,-1,-1,-1,0,0 };
int my_q[] = { 1,-1,0,1,-1,0,1,-1 };
int mx_k[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int my_k[] = { 1, -1, 1, -1, 2, -2, 2, -2 };


void move_q(int idx)
{
	int x = queen[idx].first, y = queen[idx].second;

	queue<pair<pair<int, int>, int>> q; // x,y,dir

	for (int i = 0; i < 8; ++i)
		q.push({ {x,y},i });

	while (q.size())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int dir = q.front().second;

		q.pop();

		int nx = cx + mx_q[dir];
		int ny = cy + my_q[dir];

		if (nx < 1 || ny < 1 || nx > n || ny > m)
			continue;

		if (v[nx][ny] != 0)
			continue;

		visited[nx][ny] = true;
		q.push({ {nx,ny},dir });
	}
}

void move_k(int idx)
{
	int x = knight[idx].first, y = knight[idx].second;

	for (int i = 0; i < 8; ++i)
	{
		int nx = x + mx_k[i];
		int ny = y + my_k[i];

		if (nx < 1 || ny < 1 || nx > n || ny > m)
			continue;

		visited[nx][ny] = true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int q, k, p, r, c;

	cin >> q;
	queen.resize(q);

	for (int i = 0; i < q; ++i)
	{
		cin >> r >> c;
		queen[i] = { r,c };
		v[r][c] = 1;
		visited[r][c] = true;
	}

	cin >> k;
	knight.resize(k);

	for (int i = 0; i < k; ++i)
	{
		cin >> r >> c;
		knight[i] = { r,c };
		v[r][c] = 2;
		visited[r][c] = true;
	}

	cin >> p;

	for (int i = 0; i < p; ++i)
	{
		cin >> r >> c;
		v[r][c] = 3;
		visited[r][c] = true;
	}

	for (int i = 0; i < q; ++i)
		move_q(i);

	for (int i = 0; i < k; ++i)
		move_k(i);

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (visited[i][j] == false)
				answer++;
		}
	}

	cout << answer;
	return 0;
}