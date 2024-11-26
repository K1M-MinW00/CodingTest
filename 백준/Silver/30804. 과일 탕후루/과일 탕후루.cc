#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, num;
	cin >> n;

	vector<int> v(10);
	queue<int> q;

	int cnt = 0, answer = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		q.push(num);

		if (v[num] == 0)
		{
			cnt++;
		}
		v[num]++;

		while (cnt > 2)
		{
			num = q.front();
			q.pop();

			v[num]--;
			if (v[num] == 0)
				cnt--;
		}

		int size = q.size();
		answer = max(answer, size);
	}


	cout << answer;

	return 0;
}