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

using namespace std;

int n;
vector<int> v;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());


	int num = 1;

	for (int i = 0; i < n; ++i)
	{
		if (num < v[i])
			break;
		num += v[i];
	}

	cout << num;

	return 0;
}