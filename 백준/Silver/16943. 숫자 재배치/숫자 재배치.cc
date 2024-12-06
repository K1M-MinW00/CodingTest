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

	string a;
	int b;
	cin >> a >> b;

	int temp, answer = 0;

	vector<char> v;

	for (int i = 0; i < a.length(); ++i)
		v.push_back(a[i]);

	sort(v.begin(), v.end());

	do
	{
		if (v[0] == '0')
			continue;
		string s(v.begin(), v.end());

		temp = stoi(s);
		if (temp < b)
			answer = temp;
		else
			break;
	} while (next_permutation(v.begin(), v.end()));

	if (answer)
		cout << answer;
	else
		cout << -1;

	return 0;
}