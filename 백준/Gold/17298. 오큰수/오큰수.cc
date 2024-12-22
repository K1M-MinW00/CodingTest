#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

int v[1000001];
int answer[1000001];
stack<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	memset(answer, -1, sizeof(answer));

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];

		while (st.size() && v[st.top()] < v[i])
		{
			answer[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; ++i)
		cout << answer[i] << ' ';

	return 0;
}