#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string str;

	cin >> n >> str;

	vector<int> v(n);
	stack<double> st;

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			st.push(v[str[i] - 'A']);

		else
		{
			if (st.size())
			{
				double temp = st.top();
				st.pop();
				if (str[i] == '+')
					temp += st.top();
				else if (str[i] == '-')
					temp = st.top() - temp;
				else if (str[i] == '*')
					temp *= st.top();
				else if (str[i] == '/')
					temp = st.top() / temp;
				st.pop();
				st.push(temp);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}