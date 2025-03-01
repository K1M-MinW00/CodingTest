#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int cnt = 0;

	while (n)
	{
		if (n % 2 == 1)
			cnt++;
		n /= 2;
	}

	cout << cnt;
	return 0;
}