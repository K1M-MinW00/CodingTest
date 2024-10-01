#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;

	map<int,int> A;
	int t;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		A[t]++;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		A[t]++;
	}

	int x = 0;;

	for (auto e : A)
	{
		if (e.second == 2)
			x++;
	}
	
	cout << n + m - 2 * x;

	return 0;
}