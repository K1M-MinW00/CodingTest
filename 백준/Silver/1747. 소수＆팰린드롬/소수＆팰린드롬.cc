#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
	if (num < 2)
		return false;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

bool isPalindrome(string str)
{
	string rev;

	rev = str;
	reverse(rev.begin(), rev.end());

	if (str == rev)
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = n; ; i++)
	{
		if (isPrime(i) && isPalindrome(to_string(i)))
		{
			cout << i;
			break;
		}
	}

	return 0;
}