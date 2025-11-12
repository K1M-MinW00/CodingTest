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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	set<string> s;

	while (n--)
	{
		string str;
		cin >> str;

		s.insert(str);
	}

	cin.ignore();
	while (m--)
	{
		string str;

		getline(cin, str);

		stringstream ss(str);
		string word;

		while (getline(ss, word, ','))
		{
			if (s.find(word) != s.end())
				s.erase(word);
		}
		cout << s.size() << '\n';
	}

	return 0;
}