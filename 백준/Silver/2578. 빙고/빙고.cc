#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int v[5][5];
bool visited[5][5];

int check_row()
{
	int cnt = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (visited[i][0] && visited[i][1] && visited[i][2] && visited[i][3] && visited[i][4])
			cnt++;
	}
	return cnt;
}

int check_col()
{
	int cnt = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (visited[0][i] && visited[1][i] && visited[2][i] && visited[3][i] && visited[4][i])
			cnt++;
	}
	return cnt;
}

int check_dig()
{
	int cnt = 0;

	if (visited[0][0] && visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4])
		cnt++;

	if (visited[0][4] && visited[1][3] && visited[2][2] && visited[3][1] && visited[4][0])
		cnt++;

	return cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cin >> v[i][j];
	}

	int num;
	for (int t = 1; t <= 25; ++t)
	{
		cin >> num;


		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (v[i][j] == num)
					visited[i][j] = true;
			}
		}

		int temp = 0;
		temp += check_row();
		temp += check_col();
		temp += check_dig();

		if (temp >= 3)
		{
			cout << t;
			break;
		}
	}

	return 0;
}