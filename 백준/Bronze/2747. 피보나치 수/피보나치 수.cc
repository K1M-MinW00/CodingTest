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
#define N 50

int n;
long long p[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	p[1] = 1;
	p[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		p[i] = p[i - 1] + p[i - 2];
	}

	cout << p[n];

	return 0;
}