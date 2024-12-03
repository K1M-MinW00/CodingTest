#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

string dp[251];

string stringSum(string a, string b)
{
	string result;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.length() != b.length())
	{
		b.append(a.length() - b.length(), '0');
	}

	int carry = 0, remain;

	for (int i = 0; i < a.length(); i++)
	{
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = sum / 10;
		remain = sum % 10;

		result.push_back((remain + '0'));
	}
	if (carry != 0)
		result.push_back((carry + '0'));

	reverse(result.begin(), result.end());

	return result;
}

bool operator<=(const string& a, const string& b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] > b[i])
				return false;
			else if (a[i] < b[i])
				return true;
		}
		return true;
	}

	else if (a.size() < b.size())
		return true;
	else
		return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";

	for (int i = 3; i < 251; ++i)
	{
		string temp = stringSum(dp[i - 1], dp[i - 2]);
		dp[i] = stringSum(temp, dp[i - 2]);
	}

	while (1)
	{
		cin >> n;

		if (cin.eof())
			break;

		int answer = 0;

		cout << dp[n] << '\n';
	}

	return 0;
}