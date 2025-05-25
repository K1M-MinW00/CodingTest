#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<string, string> um;
unordered_map<string, int> cnt;

string find(string a)
{
	if (um[a] == a)
		return a;
	else
		return um[a] = find(um[a]);
}

void _union(string a, string b)
{
	string A = find(a);
	string B = find(b);

	if (A == B)
		return;

	um[B] = A;
	cnt[A] += cnt[B];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, f;
	cin >> t;

	while (t--)
	{
		cin >> f;

		um.clear();
		cnt.clear();

		string a, b;

		for (int i = 0; i < f; ++i)
		{
			cin >> a >> b;

			if (um.find(a) == um.end())
			{
				um[a] = a;
				cnt[a] = 1;
			}

			if (um.find(b) == um.end())
			{
				um[b] = b;
				cnt[b] = 1;
			}

			_union(a, b);
			cout << cnt[find(a)] << '\n';
		}
	}
	return 0;
}