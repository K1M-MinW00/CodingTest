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
#include <bitset>
#include <tuple>
using namespace std;

int n, m;
vector<int> v;

void bin_search(int left, int right)
{
	int l = left, r = right, mid;
	int answer = right;

	while (l <= r)
	{
		mid = (l + r) / 2;

		int sum = 0, cnt = 0;

		for (int i = 0; i < n; ++i)
		{
			if (sum + v[i] > mid)
			{
				cnt++;
				sum = 0;
			}
			sum += v[i];
		}

		if (sum != 0)
			cnt++;

		if (cnt <= m)
		{
			r = mid - 1;
			answer = min(answer, mid);
		}

		else
			l = mid + 1;
	}

	cout << answer;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	v.resize(n);

	int left = 0;
	int right = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		left = max(left, v[i]);
		right += v[i];
	}


	bin_search(left, right);

	return 0;
}