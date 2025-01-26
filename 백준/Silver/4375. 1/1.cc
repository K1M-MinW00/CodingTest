#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;

	while (cin >> n)
	{
		if (cin.eof())
			break;

		int cnt = 1;
		int num = 1;

		while (1)
		{
			num %= n;
			if (num == 0)
			{
				cout << cnt << '\n';
				break;
			}
			num = num * 10 + 1;
			cnt++;
		}
	}

	return 0;
}