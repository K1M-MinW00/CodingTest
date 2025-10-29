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
#include <sstream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;

	long long answer = n;

	for (long i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			answer -= (answer / i);

			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
		answer -= (answer / n);

	cout << answer;

	return 0;
}