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
#define N 1000005
#define M 1005

long long v[N], s[N], c[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int l = 1, r = 1;
	int sum = 1;
	int answer = 0;

	while (l <= r)
	{
		if (sum < n)
		{
			r++;
			sum += r;
		}
		else if (sum > n)
		{
			sum -= l;
			l++;
		}
		else
		{
			answer++;
			r++;
			sum += r;
		}
	}

	cout << answer;

	return 0;
}