#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string num[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };

string func(int n)
{
	if (n < 10)
		return num[n];

	int d1 = n / 10;
	int d2 = n % 10;
	return num[d1] + " " + num[d2];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, int> dictionary;
	for (int i = n; i <= m; ++i)
	{
		string s = func(i);
		dictionary[s] = i;
	}

	int idx = 1;
	for (auto e : dictionary)
	{
		cout << e.second;
		if (idx % 10 == 0)
			cout << '\n';
		else
			cout << ' ';

		idx++;
	}

	return 0;
}