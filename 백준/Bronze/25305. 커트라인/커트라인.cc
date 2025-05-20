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

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	

	sort(v.begin(), v.end(),greater<int>());

	cout << v[k - 1];
	return 0;
}