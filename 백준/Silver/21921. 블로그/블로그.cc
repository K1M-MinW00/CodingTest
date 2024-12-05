#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int v[250001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, x, temp = 0;

	cin >> n >> x;

	for (int i = 1; i <= x; ++i)
	{
		cin >> v[i];
		temp += v[i];
	}

	int cnt = 1;
	int max_v = temp;

	for (int i = x + 1; i <= n; ++i)
	{
		cin >> v[i];
		temp += v[i] - v[i - x];

		if (max_v < temp)
		{
			max_v = temp;
			cnt = 1;
		}
		else if (max_v == temp)
			cnt++;
	}

	if (max_v != 0)
		cout << max_v << '\n' << cnt;
	else
		cout << "SAD";
	return 0;
}