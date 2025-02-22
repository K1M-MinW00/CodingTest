#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string str;

	int alpha[26] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		int p = 1;

		for (int j = str.length() - 1; j >= 0; --j)
		{
			alpha[str[j] - 'A'] += p;
			p *= 10;
		}
	}

	sort(alpha, alpha + 26, greater<int>());

	int answer = 0, num = 9;

	for (int i = 0; i < 26; ++i)
	{
		if (alpha[i] == 0)
			break;
		answer += alpha[i] * num--;
	}

	cout << answer;

	return 0;
}