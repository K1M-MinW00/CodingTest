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

	int n, m, num;
	cin >> n;

	int arr[100001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 1; i <= n; ++i)
	{
		cin >> num;

		pq.push({ num,i });
		arr[i] = num;
	}

	cin >> m;

	while (m--)
	{
		cin >> num;

		if (num == 1)
		{
			int i, v;
			cin >> i >> v;

			arr[i] = v;
			pq.push({ v,i });
		}
		else if (num == 2)
		{
			while (pq.size())
			{
				int smallest = pq.top().first;
				int idx = pq.top().second;

				if (arr[idx] == smallest)
				{
					cout << idx << '\n';
					break;
				}

				pq.pop();
			}
		}
	}

	return 0;
}