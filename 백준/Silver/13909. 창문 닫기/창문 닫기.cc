#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int answer = 0;
	for (int i = 1; i * i <= n; ++i)
		answer++;

	cout << answer;
	return 0;
}