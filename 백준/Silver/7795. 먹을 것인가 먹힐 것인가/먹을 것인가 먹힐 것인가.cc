#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> A(n), B(m);

		for (int i = 0; i < n; ++i)
			cin >> A[i];

		for (int i = 0; i < m; ++i)
			cin >> B[i];

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int result = 0;
		int idx = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (A[i] > B[j])
				{
					// cout << A[i] << ' ' << B[j] << '\n';
					result++;
				}
				else
				{
					// idx = j;
					break;
				}
			}
		}

		cout << result << '\n';
	}
	return 0;
}