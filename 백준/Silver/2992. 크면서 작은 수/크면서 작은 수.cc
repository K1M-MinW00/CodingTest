#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string x;
	cin >> x;

	vector<char> v(x.length());

	for (int i = 0; i < x.length(); ++i)
		v[i] = x[i];



	if (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < x.length(); ++i)
			cout << v[i];
	}
	else
		cout << 0;
	return 0;
}