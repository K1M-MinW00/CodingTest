#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>

using namespace std;

int n, m;
bool broken[10];

bool isPossible(int num)
{
	string str = to_string(num);

	for (int i = 0; i < str.length(); ++i)
	{
		if (broken[str[i] - '0'] == true)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int cur = 100, temp;

	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		broken[temp] = true;
	}

	int cnt = abs(cur - n);

	for (int i = 0; i <= 1000000; ++i)
	{
		if (isPossible(i))
		{
			temp = abs(n - i) + to_string(i).length();
			cnt = min(cnt, temp);
		}
	}

	cout << cnt;
	return 0;
}