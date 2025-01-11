#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1002
using namespace std;

int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };
int n, m, sx, sy;

char v[MAX][MAX];
int visited[MAX][MAX];
int fire[MAX][MAX];



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;

	string line;

	while (t--)
	{
		queue<pair<int, int>> p; // person
		queue<pair<int, int>> f; // fire
		bool answer = false;
		cin >> m >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> line;
			for (int j = 0; j < m; ++j)
			{
				v[i][j] = line[j];

				if (line[j] == '*')
				{
					fire[i][j] = 0;
					f.push({ i,j });
				}
				else if (line[j] == '@')
				{
					visited[i][j] = 0;
					p.push({ i,j });
				}
				else
				{
					visited[i][j] = -1;
					fire[i][j] = -1;
				}
			}
		}

		while (f.size())
		{
			int cx = f.front().first;
			int cy = f.front().second;
			f.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;

				if (fire[nx][ny] >= 0 || v[nx][ny] == '#')
					continue;

				f.push({ nx,ny });
				fire[nx][ny] = fire[cx][cy] + 1;
			}
		}

		while (p.size() && !answer)
		{
			int cx = p.front().first;
			int cy = p.front().second;
			p.pop();

			for (int i = 0; i < 4; ++i)
			{
				int nx = cx + mx[i];
				int ny = cy + my[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				{
					cout << visited[cx][cy] + 1 << '\n';
					answer = true;
					break;
				}

				if (visited[nx][ny] >= 0 || v[nx][ny] == '#')
					continue;

				if (fire[nx][ny] != -1 && visited[cx][cy] + 1 >= fire[nx][ny])
					continue;

				p.push({ nx,ny });
				visited[nx][ny] = visited[cx][cy] + 1;
			}
		}

		if (!answer)
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}
