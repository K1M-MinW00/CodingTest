#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, price;

	cin >> n >> price;

	vector<int> coin(n, 0);
	int start;
	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
		if (coin[i] <= price)
			start = i;
	}

	int answer = 0;

	while (price)
	{
		int num = price / coin[start];
		price -= coin[start] * num;
		answer += num;
		start--;
	}

	cout << answer;

	return 0;
}