#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int n, idx = 0;;
string s;

vector<vector<int>> v;

void solve(int r, int c, int size)
{
	char e = s[idx++];

	if (e == 'Q')
	{
		size /= 2;
		solve(r, c, size);
		solve(r, c + size, size);
		solve(r + size, c, size);
		solve(r + size, c + size, size);
	}
	else
	{
		for (int i = r; i < r + size; ++i)
		{
			for (int j = c; j < c + size; ++j)
			{
				if (e == 'W')
					v[i][j] = 0;
				else
					v[i][j] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> s; // W : 0 , B : 1

	v.resize(n);

	for (int i = 0; i < n; ++i)
		v[i].resize(n);

	int r = 0, c = 0;

	solve(r, c, n);


	cout << "#define quadtree_width " << n << '\n';
	cout << "#define quadtree_height " << n << '\n';
	cout << "static char quadtree_bits[] = {" << '\n';

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			sum += v[i][j] * pow(2, j % 8);
			if (j % 8 == 7)
			{
				cout << "0x" << hex << setw(2) << setfill('0') << sum << ',';
				sum = 0;
			}
		}
		cout << '\n';
	}

	cout << "};";
	return 0;
}