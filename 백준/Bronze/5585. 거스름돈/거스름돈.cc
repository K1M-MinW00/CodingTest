#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int remain = 1000 - n;

	int coins[] = { 500,100,50,10,5,1 };

	int answer = 0;

	for (int i = 0; i < 6; ++i)
	{
		answer += remain / coins[i];
		remain %= coins[i];

		if (remain == 0)
			break;
	}

	cout << answer;

	return 0;
}