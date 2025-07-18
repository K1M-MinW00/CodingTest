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

	int n, a, b;
	cin >> n >> a >> b;

	int cnt = 0;

	while (a != b)
	{
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		cnt++;
	}

	cout << cnt;

	return 0;
}