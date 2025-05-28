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

using namespace std;
long long n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	long long sum = 0, s = 1;

	while (n)
	{
		if (n % 2 == 1)
			sum += s;
		s *= 3;
		n >>= 1;
	}

	cout << sum;

	return 0;
}