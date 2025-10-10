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

int mr[] = { 1,-1,1,-1,2,2,-2,-2 };
int mc[] = { 2,2,-2,-2,1,-1,1,-1 };

bool visited[6][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	int tr, tc, r, c, sr, sc;

	cin >> input;

	r = '6' - input[1];
	c = input[0] - 'A';

	sr = r, sc = c;
	visited[r][c] = true;

	bool valid;

	for (int i = 1; i < 36; ++i)
	{
		cin >> input;

		tr = '6' - input[1];
		tc = input[0] - 'A';

		valid = false;

		for (int j = 0; j < 8; ++j)
		{
			int nr = r + mr[j];
			int nc = c + mc[j];

			if (nr == tr && nc == tc && !visited[nr][nc])
			{
				r = nr, c = nc;
				visited[r][c] = true;
				valid = true;
				break;
			}
		}

		if (valid)
			continue;
		else
			break;
	}

	if (valid)
	{
		valid = false;
		for (int i = 0; i < 8; ++i)
		{
			int nr = r + mr[i];
			int nc = c + mc[i];

			if (nr == sr && nc == sc)
			{
				valid = true;
				break;
			}
		}
	}

	if (valid)
		cout << "Valid";
	else
		cout << "Invalid";

	return 0;
}