#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	vector<long long> v = { 1,1,1,2,2,3,4,5,7,9,12 };

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;


		if (N > v.size())
		{
			int start = v.size();
			v.resize(N + 1);
			for (int j = start; j <= N; ++j)
			{
				v[j] = v[j - 1] + v[j - 5];
			}
		}
		cout << v[N - 1] << '\n';
	}

	return 0;
}