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

using namespace std;
#define N 1000000

long long v[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;

	long long a, b, c;

	for (long long i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	cin >> b >> c;

	long long answer = 0;

	for (long long i = 0; i < n; ++i)
	{
		v[i] -= b;
		answer++;

		if (v[i] <= 0)
			continue;

		if (v[i] % c != 0)
			answer += (v[i] / c) + 1;
		else
			answer += v[i] / c;
	}

	cout << answer;
	return 0;
}