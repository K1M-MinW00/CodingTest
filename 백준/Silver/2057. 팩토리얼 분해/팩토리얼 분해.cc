#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> f(21, 1);
vector<bool> visited(21, false);

bool solve(ll remain, int idx)
{
	if (f[idx] == remain)
		return true;


	ll cur = f[idx];
	ll r = remain - cur;

	for (int i = 0; i < idx; ++i)
	{
		if (visited[i])
			continue;

		visited[i] = true;
		if (solve(r, i))
			return true;
		visited[i] = false;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;

	ll m = 1;
	int idx = 0;
	for (int i = 2; i <= 20; ++i)
	{
		f[i] = f[i - 1] * i;
		if (f[i] <= n)
			idx = i;
	}

	if (solve(n, idx))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}