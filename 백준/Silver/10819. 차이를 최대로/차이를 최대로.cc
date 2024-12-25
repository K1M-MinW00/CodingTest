#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int answer = -1;

	sort(a.begin(), a.end());

	do
	{
		int temp = 0;
		for (int i = 0; i < n - 1; ++i)
			temp += abs(a[i] - a[i + 1]);

		if (answer < temp)
			answer = temp;

	} while (next_permutation(a.begin(), a.end()));

	cout << answer;
	return 0;
}