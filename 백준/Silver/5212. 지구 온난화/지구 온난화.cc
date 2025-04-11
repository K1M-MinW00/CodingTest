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

using namespace std;

int r, c;
char v[12][12];
int mx[] = { 1,-1,0,0 };
int my[] = { 0,0,1,-1 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
    
    for(int i=0;i<12;++i)
        for(int j=0;j<12;++j)
            v[i][j] = '.';
    
	string line;

	for (int i = 1; i <= r; ++i)
	{
		cin >> line;
		for (int j = 1; j <= c; ++j)
			v[i][j] = line[j - 1];
	}

	vector<pair<int, int>> temp;

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			int cnt = 0;

			for (int k = 0; k < 4; ++k)
			{
				int nx = i + mx[k];
				int ny = j + my[k];

				if (v[nx][ny] == '.')
					cnt++;
			}

			if (cnt >= 3)
				temp.push_back({ i,j });
		}
	}


	for (auto t : temp)
		v[t.first][t.second] = '.';


	int min_r = 11, min_c = 11, max_r = 0, max_c = 0;

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (v[i][j] == 'X')
			{
				min_r = min(min_r, i);
				max_r = max(max_r, i);
				min_c = min(min_c, j);
				max_c = max(max_c, j);
			}
		}
	}

	for (int i = min_r; i <= max_r; ++i)
	{
		for (int j = min_c; j <= max_c; ++j)
			cout << v[i][j];
		cout << '\n';
	}

	return 0;
}