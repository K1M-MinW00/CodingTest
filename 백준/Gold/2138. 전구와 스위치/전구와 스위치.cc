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

int n, cnt = 0, answer;
string s, e, temp;

void Turn(int idx)
{
	if (idx > 0)
		temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
	temp[idx] = (temp[idx] == '0') ? '1' : '0';
	if (idx < n - 1)
		temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}

void solve(int idx)
{
	temp = s;
	cnt = 0;

	if (idx == 0)
	{
		temp[0] = (temp[0] == '0') ? '1' : '0';
		temp[1] = (temp[1] == '0') ? '1' : '0';
		cnt++;
	}

	for (int i = 1; i < n; ++i)
	{
		if (temp[i - 1] != e[i - 1])
		{
			Turn(i);
			cnt++;
		}
	}

	if (temp == e)
		answer = min(answer, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> s >> e;

	answer = INT_MAX;

	solve(0);
	solve(1);

	if (answer != INT_MAX)
		cout << answer;
	else
		cout << -1;

	return 0;
}