#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int n = str.length();
	vector<string> v;

	for (int i = 0; i < n; ++i)
	{
		string temp = str.substr(i, n);

		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (auto e : v)
		cout << e << '\n';
	return 0;
}