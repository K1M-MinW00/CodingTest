#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <climits>
#include <stack>
#include <queue>

using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, l;
	cin >> n >> w >> l;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int weight = 0, time = 0;
	queue<int> q;

	for (int i = 0; i < n; ++i)
	{
		while (1)
		{
			if (q.size() == w)
			{
				weight -= q.front();
				q.pop();
			}
			if (weight + v[i] <= l)
				break;

			q.push(0);
			time++;
		}

		weight += v[i];
		q.push(v[i]);
		time++;
	}

	cout << time + w;
	return 0;
}