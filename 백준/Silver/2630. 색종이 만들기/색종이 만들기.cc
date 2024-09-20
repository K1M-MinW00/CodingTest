#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
int b = 0,w = 0;

void Recursive(int x, int y,int s)
{
	int cur = v[x][y];

	for (int i = x; i < x + s; ++i)
	{
		for (int j = y; j < y + s; ++j)
		{
			if (cur != v[i][j])
			{
				Recursive(x, y, s / 2);
				Recursive(x, y + s / 2, s / 2);
				Recursive(x + s / 2, y, s / 2);
				Recursive(x + s / 2, y + s / 2, s / 2);
				return;
			}
		}
	}

	if (cur == 1)
		b++;
	else if (cur == 0)
		w++;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		v[i].resize(n);
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	Recursive(0, 0, n);

	cout << w << '\n' << b;
	return 0;
}