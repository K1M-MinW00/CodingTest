#include <iostream>
#include <vector>
using namespace std;

int n, s, cnt = 0;

vector<int> arr;

void solve(int idx, int sum)
{

	if (idx == n)
		return;
	
	if (sum + arr[idx] == s)
	{
		cnt++;
	}


	solve(idx + 1, sum + arr[idx]);
	solve(idx + 1, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	arr.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	solve(0, 0);

	cout << cnt;
	return 0;
}