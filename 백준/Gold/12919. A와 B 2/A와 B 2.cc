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

using namespace std;

bool answer = false;
void solve(string a, string b)
{
	if (a == b)
	{
		answer = true;
		return;
	}

	if (a.length() > b.length())
	{
		return;
	}

	if (b.back() == 'A')
	{
		string temp = b;
		temp.erase(temp.size() - 1);
		solve(a, temp);
	}

	if (b.front() == 'B')
	{
		string temp = b;
		reverse(temp.begin(), temp.end());
		temp.erase(temp.size() - 1);
		solve(a, temp);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	solve(a, b);

	cout << answer;
	return 0;
}