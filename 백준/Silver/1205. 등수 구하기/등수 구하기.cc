#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s, p;
	cin >> n >> s >> p;

	int v[51];

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int cnt = 0;
	int idx = 1;

	for (int i = 0; i < n; ++i)
	{
		if (s < v[i])
			idx++;
		else if (s > v[i])
			break;

		cnt++;
	}

	if (cnt == p)
		idx = -1;

	if (n == 0)
		idx = 1;

	cout << idx;

	return 0;
}