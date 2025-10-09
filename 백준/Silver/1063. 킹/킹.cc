#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;
#define N 51

string k, s;
int n;

int mx[] = { 0,0,1,-1,-1,-1,1,1 };
int my[] = { 1,-1,0,0,1,-1,1,-1 };

map<string, int> m;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	m.insert({ "R", 0 });
	m.insert({ "L", 1 });
	m.insert({ "B", 2 });
	m.insert({ "T", 3 });
	m.insert({ "RT", 4 });
	m.insert({ "LT", 5 });
	m.insert({ "RB", 6 });
	m.insert({ "LB", 7 });

	int kx, ky, sx, sy;

	cin >> k >> s;


	ky = k[0] - 'A';
	kx = '8' - k[1];

	sy = s[0] - 'A';
	sx = '8' - s[1];

	cin >> n;

	string op;

	for (int i = 0; i < n; ++i)
	{
		cin >> op;

		int idx = m[op];
		int nx = kx + mx[idx];
		int ny = ky + my[idx];

		if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8)
			continue;

		if (nx == sx && ny == sy)
		{
			int nsx = sx + mx[idx];
			int nsy = sy + my[idx];

			if (nsx < 0 || nsy < 0 || nsx >= 8 || nsy >= 8)
				continue;

			sx = nsx;
			sy = nsy;
		}

		kx = nx;
		ky = ny;
	}

	k[0] = ky + 'A';
	k[1] = '8' - kx;

	s[0] = sy + 'A';
	s[1] = '8' - sx;

	cout << k << '\n' << s << '\n';
	return 0;
}