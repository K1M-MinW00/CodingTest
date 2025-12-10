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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;

const int INF = 1e9 + 4;

int n, lis[1000004], len, num;
pair<int, int> ans[1000004];
stack<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(lis, lis + 1000004, INF);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = (int)(lower_bound(lis, lis + len, num) - lis);

		if (*lowerPos == INF)
			len++;

		*lowerPos = num;
		ans[i] = { _pos,num };
	}

	cout << len << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i].first == len - 1)
		{
			st.push(ans[i].second);
			len--;
		}
	}

	while (st.size())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}