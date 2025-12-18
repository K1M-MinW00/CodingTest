#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int n;
vector<int> v, L, R;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.resize(n);
	L.resize(n);
	R.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	L[0] = v[0];
	int answer = L[0];

	for (int i = 1; i < n; ++i)
	{
		L[i] = max(L[i - 1] + v[i], v[i]);
		answer = max(answer, L[i]);
	}

	R[n - 1] = v[n - 1];

	for (int i = n - 2; i >= 0; --i)
	{
		R[i] = max(R[i + 1] + v[i], v[i]);
	}

	for (int i = 1; i < n - 1; ++i)
	{
		int temp = L[i - 1] + R[i + 1];
		answer = max(answer, temp);
	}

	cout << answer;

	return 0;
}