#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<int> p;
	vector<int> v(m);
	int x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		p.push(x);
	}

	for (int i = 0; i < m; ++i)
		cin >> v[i];

	int answer = 1;

	for(int i=0;i<m;++i)
	{
		int c = p.top();
		p.pop();
		if (v[i] > c)
		{
			answer = 0;
			break;
		}

		int remain = c - v[i];
		if (remain > 0)
		{
			p.push(remain);
		}
	}

	cout << answer;
	return 0;
}