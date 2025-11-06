#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <bitset>
#include <tuple>

using namespace std;

int t;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		priority_queue<long long, vector<long long>, greater<long long>> pq;

		for (int i = 0; i < k; ++i)
		{
			int num;
			cin >> num;

			pq.push(num);
		}

		long long answer = 0;
		while (pq.size()>1)
		{
			long long first = pq.top();
			pq.pop();
			long long second = pq.top();
			pq.pop();

			long long sum = first + second;
			answer += sum;
			pq.push(sum);
		}

		cout << answer << '\n';
	}

	return 0;
}