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

	map<string, int> m;

	while (n--)
	{
		string s;
		cin >> s;

		sort(s.begin(), s.end());
		m[s]++;
	}

	cout << m.size();

	return 0;
}