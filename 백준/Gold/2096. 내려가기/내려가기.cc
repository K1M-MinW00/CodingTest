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

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int maxDP[3], minDP[3], input[3];

	for (int i = 0; i < 3; ++i)
	{
		cin >> input[i];
		maxDP[i] = input[i];
		minDP[i] = input[i];
	}


	for (int i = 1; i < n; ++i)
	{
		cin >> input[0] >> input[1] >> input[2];

		int temp0 = maxDP[0], temp2 = maxDP[2];
		maxDP[0] = max(maxDP[0], maxDP[1]) + input[0];
		maxDP[2] = max(maxDP[1], maxDP[2]) + input[2];
		maxDP[1] = max(max(temp0, temp2), maxDP[1]) + input[1];

		temp0 = minDP[0], temp2 = minDP[2];
		minDP[0] = min(minDP[0], minDP[1]) + input[0];
		minDP[2] = min(minDP[1], minDP[2]) + input[2];
		minDP[1] = min(min(temp0, temp2), minDP[1]) + input[1];

	}

	int maxV = INT_MIN;
	int minV = INT_MAX;

	for (int i = 0; i < 3; ++i)
	{
		maxV = max(maxDP[i], maxV);
		minV = min(minDP[i], minV);
	}

	cout << maxV << ' ' << minV;
	return 0;
}