#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

string s;
int cnt;

int recursion(int l, int r)
{
	cnt++;
	if (l >= r)
		return 1;

	else if (s[l] != s[r])
		return 0;
	else
		return recursion(l + 1, r - 1);
}

int isPalindrome()
{
	return recursion(0, s.length() - 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{

		cin >> s;

		cnt = 0;
		cout << isPalindrome() << ' ' << cnt << '\n';
	}

	return 0;
}