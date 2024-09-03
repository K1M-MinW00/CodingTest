#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	int start = round((float)(n * 15) / 100);

	float sum = 0;
	vector<int> score(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin >> score[i];
		sum += score[i];
	}

	sort(score.begin(), score.end());

	for (int i = 0; i < start; ++i)
		sum -= score[i];

	for (int i = n - 1; i > n - 1 - start; --i)
		sum -= score[i];

	int avg = round((float)sum / (n - 2 * start));

	cout << avg;
	return 0;
}