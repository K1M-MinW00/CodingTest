#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int temp, idx = 1;
	stack<int> st;

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		st.push(temp);

		while (st.size())
		{
			if (st.top() == idx)
			{
				st.pop();
				idx++;
			}
			else
				break;
		}
	}

	if (st.size())
		cout << "Sad";
	else
		cout << "Nice";

	return 0;
}