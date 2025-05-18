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

char v[5][16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;

	for (int i = 0; i < 5; ++i)
	{
		cin >> str;

		for (int j = 0; j < str.length(); ++j)
			v[i][j] = str[j];
	}


	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (v[j][i] == NULL)
				continue;

			cout << v[j][i];
		}
	}
	return 0;
}