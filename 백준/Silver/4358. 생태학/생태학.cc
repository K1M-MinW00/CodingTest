#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, float> speices;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	int total = 0;

	while (getline(cin, str))
	{
		total++;
		speices[str]++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto i = speices.begin(); i != speices.end(); i++)
	{
		float p = i->second / (float)total * 100;
		cout << i->first << ' ';
		cout << p << '\n';
	}

	return 0;
}