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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int d = 2;

	while (n!=1)
	{
		if (n % d == 0)
		{
			cout << d << '\n';
			n /= d;
		}
		else
			d++;
	}

	
	return 0;
}