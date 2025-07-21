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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<long long> negative, positive;
	int zero = 0, one = 0;

	for (int i = 0; i < n; ++i)
	{
		long long num;
		cin >> num;

		if (num == 0)
			++zero;
		else if (num == 1)
			++one;

		else if (num < 0)
			negative.push_back(num);
		else
			positive.push_back(num);
	}

	sort(negative.begin(), negative.end());
	sort(positive.begin(), positive.end(), greater<long long>());

	long long sum = 0;

	for (int i = 0; i < (int)positive.size() - 1; i += 2)
	{
		sum += positive[i] * positive[i + 1];
	}

	if (positive.size() % 2 == 1)
		sum += positive.back();

	sum += one;

	for (int i = 0; i < (int)negative.size() - 1; i += 2)
	{
		sum += negative[i] * negative[i + 1];
	}

	if (negative.size() % 2 == 1 && zero == 0)
		sum += negative.back();

	cout << sum;
	return 0;
}