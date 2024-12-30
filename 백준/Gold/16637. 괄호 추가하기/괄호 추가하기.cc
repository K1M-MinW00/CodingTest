#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int n, answer = -987654321;
string s;
vector<int> num;
vector<char> op;

int calculate(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
}

void solve(int idx, int cur)
{
	if (idx == num.size() - 1)
	{
		answer = max(answer, cur);
		return;
	}

	int result = calculate(cur, num[idx + 1], op[idx]);
	solve(idx + 1, result);

	if (idx + 2 <= num.size() - 1)
	{
		int next = calculate(num[idx + 1], num[idx + 2], op[idx + 1]);
		int result = calculate(cur, next, op[idx]);
		solve(idx + 2, result);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0)
			num.push_back(s[i] - '0');
		else
			op.push_back(s[i]);
	}

	solve(0, num[0]);

	cout << answer;
	return 0;
}