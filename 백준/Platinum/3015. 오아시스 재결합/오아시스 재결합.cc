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

	int n, num;
	cin >> n;

	stack<pair<long long, long long>> st;

	long long answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		int cnt = 1;

		while (st.size() && st.top().first <= num)
		{
			answer += st.top().second;

			if (st.top().first == num)
				cnt = st.top().second + 1;
			else
				cnt = 1;

			st.pop();
		}

		if (st.size())
			answer++;

		st.push({ num,cnt });
	}

	cout << answer;
	return 0;
}