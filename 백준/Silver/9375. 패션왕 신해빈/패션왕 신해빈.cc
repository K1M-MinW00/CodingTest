#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n, k;
	string name,type;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		map < string,vector<string>> m;

		for (int j = 0; j < k; ++j)
		{
			cin >> name >> type;

			if (m.find(type) != m.end())
			{
				m[type].push_back(name);
			}
			else
			{
				vector<string> temp;
				temp.push_back(name);
				m[type] = temp;
			}
		}

		int answer = 1;

		for (auto e : m)
			answer *= (e.second.size()+1);

		cout << answer - 1 << '\n';
	}

	return 0;
}