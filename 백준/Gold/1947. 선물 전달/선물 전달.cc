#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

long long v[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	v[1] = 0;
	v[2] = 1;
	v[3] = 2;

	for (int i = 4; i <= n; ++i)
	{
		v[i] = (i - 1) * (v[i - 2] + v[i - 1]) % 1000000000;
	}

	cout << v[n];

	return 0;
}