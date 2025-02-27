#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int>> st;
	int temp;

	for (int i = 1; i <= n; ++i)
	{
		cin >> temp;

		if (st.empty())
		{
			st.push({ i,temp });
			cout << 0 << ' ';
		}
		else
		{
			while (st.size())
			{
				if (st.top().second > temp)
				{
					cout << st.top().first << ' ';
					break;
				}
				else
					st.pop();
			}

			if (st.empty())
				cout << 0 << ' ';
			st.push({ i,temp });
		}
	}
	return 0;
}