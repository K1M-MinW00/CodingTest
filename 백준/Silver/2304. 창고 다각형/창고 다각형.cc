#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int v[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int max_h = 0, max_l;
	for (int i = 0; i < n; ++i)
	{
		int l, h;
		cin >> l >> h;

		v[l] = h;

		if (max_h < h)
		{
			max_h = h;
			max_l = l;
		}
	}

	int answer = 0;

	int cur_h = 0;
	for (int i = 1; i < max_l; ++i)
	{
		cur_h = max(cur_h, v[i]);
		answer += cur_h;
	}

	answer += max_h;

	cur_h = 0;
	for (int i = 1000; i > max_l; --i)
	{
		cur_h = max(cur_h, v[i]);
		answer += cur_h;
	}

	cout << answer;

	return 0;
}