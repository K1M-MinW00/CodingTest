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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string k;
	cin >> k;


	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		if (k[i] == '1')
			cnt++;
	}

	cout << cnt;

	return 0;
}