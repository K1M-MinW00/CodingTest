#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int arr[11] = { 0, };

	for (int i = 1; i <= n; ++i)
	{
		int input;
		cin >> input;

		int idx = 0, left = 0;

		while (left != input)
		{
			if (arr[idx] == 0)
			{
				idx++;
				left++;
			}
			else
			{
				idx++;
			}
		}

		while (arr[idx] != 0)
			idx++;
		arr[idx] = i;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	return 0;
}