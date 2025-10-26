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

	int n;
	cin >> n;

	int cur = 1;
	int num;
	stack<int> st;
	vector<char> answer;
	bool solve = true;
	for (int i = 1; i <= n; ++i)
	{
		cin >> num;

		if (!solve)
			continue;

		if (num >= cur)
		{
			while (cur <= num)
			{
				st.push(cur++);
				answer.push_back('+');
			}

			st.pop();
			answer.push_back('-');
		}
		else
		{
			if (st.top() == num)
			{
				st.pop();
				answer.push_back('-');
			}
			else
			{
				solve = false;
			}
		}
	}

	if (solve)
	{
		for (int i = 0; i < answer.size(); ++i)
			cout << answer[i] << '\n';
	}
	else
		cout << "NO";
	return 0;
}