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

	int n, l, num;
	cin >> n >> l;

	deque<pair<int, int>> dq; // idx - value

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		while (dq.size() && dq.back().second > num)
			dq.pop_back();

		dq.push_back({ i,num });

		if (i - dq.front().first >= l)
			dq.pop_front();

		cout << dq.front().second << ' ';
	}

	return 0;
}