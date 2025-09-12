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
		
        for(int i = 0;i < n; ++i)
        {
            auto pos = lower_bound(B.begin(),B.end(),A[i]);
            result += (int)(pos - B.begin());
        }

		cout << result << '\n';
	}
	return 0;
}