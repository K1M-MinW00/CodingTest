#include <iostream>
#include <vector>
using namespace std;

int n;
int result = 0;

int col[16];

bool promising(int i)
{
	int k = 0;
	bool flag = true;

	while (k < i && flag)
	{
		if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
			flag = false;
		k++;
	}
	return flag;
}

void queens(int i)
{
	if (i == n)
	{
		result++;
		return;
	}

	for (int j = 0; j < n; ++j)
	{
		col[i] = j;
		if (promising(i))
			queens(i + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	queens(0);

	cout << result;
	return 0;
}