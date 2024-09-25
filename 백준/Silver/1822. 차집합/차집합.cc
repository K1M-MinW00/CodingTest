#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n >> m;

	set<int> A;
	
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;

		A.insert(t);
	}

	for (int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
			
		if(A.find(t)!=A.end())
			A.erase(t);
	}

	cout << A.size() << '\n';

	for (auto e : A)
		cout << e << ' ';

	return 0;
}