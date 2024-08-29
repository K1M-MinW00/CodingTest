#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	map<string, int> book;
	vector<string> names;
	vector<string> answer;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		string name;
		cin >> name;

		names.push_back(name);
		book.insert(make_pair(name, i));
	}


	for (int i = 0; i < m; ++i)
	{
		string query;
		cin >> query;

		if (query[0] >= 65 && query[0] <= 90)
		{
			answer.push_back(to_string(book[query]));
		}

		else
		{
			answer.push_back(names[stoi(query) - 1]);
		}
	}

	for (int i = 0; i < m; ++i)
		cout << answer[i] << '\n';

	return 0;
}