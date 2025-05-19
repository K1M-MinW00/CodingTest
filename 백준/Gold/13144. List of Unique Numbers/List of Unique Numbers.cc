#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define N 100005

bool visited[N];
vector<int> v;
int n;
long long answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int left = 0, right = 0;

	while (right < n)
	{
		int lvalue = v[left];
		int rvalue = v[right];

		if (visited[rvalue] == false)
		{
			visited[rvalue] = true;
			right++;
		}
		else
		{
			answer += (right - left);
			left++;
			visited[lvalue] = false;
		}
	}

	answer += (long long)(right - left) * (right - left + 1) / 2;
	cout << answer << '\n';
	return 0;
}