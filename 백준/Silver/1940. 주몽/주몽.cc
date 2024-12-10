#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, num;
	cin >> n;
	cin >> m;

	set<int> s;
	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;

		if (s.find(m - num) != s.end())
			answer++;
		else
			s.insert(num);
	}

	cout << answer;
	return 0;
}