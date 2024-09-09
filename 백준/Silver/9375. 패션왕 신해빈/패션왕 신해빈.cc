#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n, k;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> k;

		map<string, vector<string>> m;

		for (int j = 0; j < k; ++j)
		{
			string name, type;
			cin >> name >> type;

			if (m.find(type) != m.end())
			{
				m[type].push_back(name);
			}

			else
			{
				vector<string> temp = { name };
				m.insert(make_pair(type, temp));
			}
		}

		vector<int> answer;
		int result = 1;

		for (auto it = m.begin(); it != m.end(); it++)
		{
			int cnt = it->second.size();
			answer.push_back(cnt);
		}

		for (int j = 0; j < answer.size(); ++j)
		{
			result *= (answer[j] + 1);
		}
		cout << result - 1 << '\n';
	}

	return 0;
}