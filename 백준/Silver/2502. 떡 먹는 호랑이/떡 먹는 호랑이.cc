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

using namespace std;

int d, k;
vector<int> a,b;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> d >> k;

	a.resize(d + 1);
	b.resize(d + 1);

	a[1] = 1;
	b[1] = 0;
	a[2] = 0;
	b[2] = 1;

	for (int i = 3; i <= d; ++i)
	{
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	for (int i = 1; i <= k; ++i)
	{
		int remain = k - (i * a[d]);
		if (remain % b[d] == 0)
		{
			cout << i << '\n' << remain / b[d];
			return 0;
		}
	}
	

	return 0;
}