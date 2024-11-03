#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	sort(v.begin(), v.end(),greater<int>());

	int max = 0;

	for (int i = 0; i <n; ++i)
	{
		if (max < (i + 1) + v[i])
			max = v[i] + i + 1;
	}

	cout << max + 1;
	
	return 0;
}