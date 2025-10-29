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
#include <tuple>
#include <sstream>
using namespace std;

#define N 10000001

int n;
bool v[N];
bool isPalindrome(int n)
{
	string str = to_string(n);

	int l = str.length();

	for (int i = 0; i <= l / 2; ++i)
	{
		if (str[i] != str[l - 1 - i])
			return false;
	}
	return true;
}
void sieve()
{
	v[1] = false;

	for (int i = 2; i < N; ++i)
		v[i] = true;

	for (int i = 2; i * i <= N; ++i)
	{
		if (v[i] == 0)
			continue;

		for (int j = i + i; j < N; j += i)
		{
			v[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	sieve();

	for (int i = n; i < N; ++i)
	{
		if (v[i] != 0 && isPalindrome(i))
		{
			cout << i;
			break;
		}
	}

	return 0;
}