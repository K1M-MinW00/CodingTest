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

	vector<int> v(5);
	int sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	cout << sum / 5 << '\n';
	cout << v[2];
	return 0;
}