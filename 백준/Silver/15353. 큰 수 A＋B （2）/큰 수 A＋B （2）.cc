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

using namespace std;


string str_add(string a, string b)
{
	int sum = 0;
	string ret;

	while (a.size() || b.size() || sum)
	{
		if (a.size())
		{
			sum += a.back() - '0';
			a.pop_back();
		}

		if (b.size())
		{
			sum += b.back() - '0';
			b.pop_back();
		}

		ret += (sum % 10) + '0';
		sum /= 10;
	}

	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;

	cin >> a >> b;

	string answer = str_add(a, b);

	cout << answer;
	return 0;
}