#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <regex>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j * i <= n; ++j)
		{
			arr[i]++;
		}
	}

	long long sum = 0;

	for (int i = 1; i <= n; ++i)
		sum += arr[i] * i;

	cout << sum;
	return 0;
}