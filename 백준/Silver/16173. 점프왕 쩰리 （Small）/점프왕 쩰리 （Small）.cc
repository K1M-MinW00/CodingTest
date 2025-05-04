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

using namespace std;

int n, m, r;

int v[3][3];
int mx[] = { 1,0 };
int my[] = { 0,1 };

bool solve()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (q.size())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		int c = v[cx][cy];
		q.pop();


		if (c == 0)
			continue;

		for (int i = 0; i < 2; ++i)
		{
			int nx = cx + c * mx[i];
			int ny = cy + c * my[i];

			if (nx >= n || ny >= n)
				continue;

			if(v[nx][ny] == -1)
				return true;

			q.push({ nx,ny });
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	
	bool answer = solve();

	if (answer)
		cout << "HaruHaru";
	else
		cout << "Hing";

	return 0;
}