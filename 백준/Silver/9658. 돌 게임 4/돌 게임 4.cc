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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v[1001];

	int n;
	cin >> n;

	v[1] = v[3] = 0;
	v[2] = v[4] = v[5] = 1;

	for (int i = 6; i <= n; ++i)
	{
		if (v[i - 1] == 1 && v[i - 3] == 1 && v[i - 4] == 1)
			v[i] = 0;
		else
			v[i] = 1;
	}

	cout << (v[n] == 1 ? "SK" : "CY");


	return 0;
}