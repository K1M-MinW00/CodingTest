#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string sum(string x, string y)
{
	int num;
	int carry = 0;
	string result;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	if (x.length() > y.length())
		while (x.length() != y.length())
			y += '0';

	else if (x.length() < y.length())
		while (x.length() != y.length())
			x += '0';

	for (int i = 0; i < x.length(); ++i)
	{
		int temp = x[i] - '0' + y[i] - '0' + carry;
		num = temp % 10;
		result += to_string(num);
		carry = temp / 10;
	}

	if (carry)
		result += to_string(carry);

	reverse(result.begin(), result.end());

	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(10001);

	v[0] = '0';
	v[1] = '1';

	for (int i = 2; i <= n; ++i)
	{
		v[i] = sum(v[i - 1], v[i - 2]);
	}

	cout << v[n];

	return 0;
}