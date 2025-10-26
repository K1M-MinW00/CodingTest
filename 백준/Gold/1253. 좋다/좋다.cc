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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		int temp = v[i];
		int l = 0, r = n - 1;

		while (l < r)
		{
			int sum = v[l] + v[r];

			if (sum == temp)
			{
				if (i != l && i != r)
				{
					answer++;
					break;
				}
				else if (i == l)
					l++;
				else if (i == r)
					r--;
			}
			else if (sum < temp)
				l++;
			else
				r--;
		}
	}

	cout << answer;

	return 0;
}