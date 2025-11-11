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
#include <tuple>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	int sum = 0, num;
	int star_idx = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] != '*')
		{
			num = str[i] - '0';

			if (i % 2 == 1)
				num *= 3;

			sum += num;
		}
		else
			star_idx = i;
	}

	int mul = (star_idx % 2 == 0) ? 1 : 3;

	for (int i = 0; i < 10; ++i)
	{
		if ((sum + mul * i) % 10 == 0)
		{
			cout << i;
			break;
		}
	}

	return 0;
}