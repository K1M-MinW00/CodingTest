#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, temp;
	cin >> n;

	vector<int> minus;
	vector<int> plus;

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;

		if (temp > 0)
			plus.push_back(temp);
		else
			minus.push_back(temp);
	}

	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());

	int answer = 0;

	int p = plus.size(), m = minus.size();

	if (p % 2 != 0)
		answer += plus.back();
	if (m % 2 != 0)
		answer += minus.back();

	for (int i = 0; i < p - 1; i += 2)
	{
		if (plus[i + 1] == 1)
			answer += plus[i] + plus[i + 1];
		else if (plus[i + 1] > 0)
			answer += plus[i] * plus[i + 1];
	}

	for (int i = 0; i < m - 1; i += 2)
		answer += minus[i] * minus[i + 1];

	cout << answer;

	return 0;
}