#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	vector<int> answer;
	queue<int> q;
	for (int i = 1; i <= n; ++i)
		q.push(i);

	
	int cnt = 0;
	while (q.size() >1)
	{
		int top = q.front();
		q.pop();
		cnt++;

		if (cnt == k)
		{
			answer.push_back(top);
			cnt = 0;
		}
			

		else
			q.push(top);
	}

	answer.push_back(q.front());

	cout << "<";

	for (int i = 0; i < answer.size()-1; ++i)
	{
		cout << answer[i] << ", ";
	}

	cout << answer.back() << ">";
}