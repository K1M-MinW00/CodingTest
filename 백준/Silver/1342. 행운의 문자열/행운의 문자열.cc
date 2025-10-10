#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <bitset>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	sort(s.begin(), s.end());

	int answer = 0;

	do
	{
		bool check = true;

		for (int i = 0; i < s.length() - 1; ++i)
		{
			if (s[i] == s[i + 1])
			{
				check = false;
				break;
			}
		}

		if (check)
			answer++;
	} while (next_permutation(s.begin(), s.end()));

	cout << answer;

	return 0;
}