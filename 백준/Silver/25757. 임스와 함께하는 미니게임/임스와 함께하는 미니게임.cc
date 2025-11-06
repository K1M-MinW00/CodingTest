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

using namespace std;

int t;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	char c;

	cin >> n >> c;

	set<string> s;

	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		s.insert(name);
	}

	int num = s.size();
	
	if (c == 'F')
		num /= 2;
	else if (c == 'O')
		num /= 3;

	cout << num;
	return 0;
}