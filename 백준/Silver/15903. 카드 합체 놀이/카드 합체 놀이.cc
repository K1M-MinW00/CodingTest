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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		pq.push(temp);
	}


	for (int i = 0; i < m; ++i)
	{
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();

		long long sum = first + second;
		pq.push(sum);
		pq.push(sum);
	}

	long long answer = 0;

	while (pq.size())
	{
		answer += pq.top();
		pq.pop();
	}

	cout << answer;

	return 0;
}