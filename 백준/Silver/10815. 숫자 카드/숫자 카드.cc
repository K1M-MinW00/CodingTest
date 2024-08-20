#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
	int n, m, num;
	cin >> n;

	unordered_set<int> uos;
	vector<int> answer;

	for (int i = 0; i < n; ++i)
	{

		cin >> num;

		uos.insert(num);
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> num;

		if (uos.find(num) != uos.end())
			answer.push_back(1);
		else
			answer.push_back(0);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << ' ';

	return 0;
}