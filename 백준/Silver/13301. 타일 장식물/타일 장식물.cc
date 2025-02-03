#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <regex>
using namespace std;

int arr[85] = { 0,1,1,2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 4; i <= n; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];

	if (n == 1)
		cout << 4;
	else
	{
		long long sum = arr[n] * 4 + arr[n - 1] * 2;
		cout << sum;
	}

	return 0;
}