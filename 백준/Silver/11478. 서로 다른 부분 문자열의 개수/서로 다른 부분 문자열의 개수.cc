#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.length();

	unordered_map<string, int> um;

	string tmp;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j <= n - i; ++j)
		{
			tmp = str.substr(i, j);
			um[tmp] += 1;
		}
	}

	cout << um.size();

	return 0;
}