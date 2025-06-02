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

	string str;

	while (n--)
	{
		cin >> str;

		string before = str;
		int result = next_permutation(str.begin(), str.end());

		if (result)
			cout << str << '\n';
		else
			cout << before << '\n';
	}

	return 0;
}