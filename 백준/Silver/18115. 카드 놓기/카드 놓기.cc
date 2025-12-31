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
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <sstream>
#include <deque>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, num = 1;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	deque<int> dq;

	for (int i = n - 1; i >= 0; --i)
	{
		if (v[i] == 1)
			dq.push_back(num);
		else if (v[i] == 2)
		{
			int back = dq.back();
			dq.pop_back();
			dq.push_back(num);
			dq.push_back(back);
		}
		else if (v[i] == 3)
			dq.push_front(num);

		num++;
	}

	for (int i = n - 1; i >= 0; --i)
		cout << dq[i] << ' ';

	return 0;
}