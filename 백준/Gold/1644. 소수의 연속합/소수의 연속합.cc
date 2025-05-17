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

using namespace std;
#define MAX 4000005

int n;

bool prime[MAX];
vector<int> pool;

void solve()
{
	for (int i = 2; i <= n; ++i)
	{
		if (prime[i])
			continue;

		for (int j = 2 * i; j <= n; j += i)
			prime[j] = true;
	}

	for (int i = 2; i <= n; ++i)
		if (prime[i] == false)
			pool.push_back(i);

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	solve();

	int left = 0, right = 0;
	int sum = 0, answer = 0;
	int max_idx = pool.size();

	while (1)
	{
		if (sum >= n)
			sum -= pool[left++];

		else if (right == max_idx)
			break;

		else
			sum += pool[right++];

		if (sum == n)
			answer++;
	}
	
	cout << answer; 
	return 0;
}