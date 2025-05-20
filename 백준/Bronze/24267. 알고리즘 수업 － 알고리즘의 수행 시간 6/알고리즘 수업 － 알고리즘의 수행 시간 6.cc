#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long answer = 0;
	for (long long i = 1; i <= n - 2; ++i)
		answer += ((i*i)+i)/2;

	cout << answer << '\n' << 3;

	return 0;
}