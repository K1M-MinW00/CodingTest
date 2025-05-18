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

int v[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int b;

	cin >> n >> b;

	string answer;

	while (n)
	{
		int d = n % b;
		n /= b;

		if (d >= 10)
			answer += (char)('A' + d - 10);
		else
			answer += d + '0';

	}
	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;
}