#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int input;

	stack<int> st;
	vector<char> answer;

	st.push(0);

	int idx = 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;

		while (st.top() < input)
		{
			st.push(idx);
			idx++;
			answer.push_back('+');
		}

		if (st.top() == input)
		{
			st.pop();
			answer.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';

	return 0;
}