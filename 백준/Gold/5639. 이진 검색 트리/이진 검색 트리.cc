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

void solve(int s, int e)
{
	if (s >= e)
		return;

	if (s == e - 1)
	{
		cout << v[s] << '\n';
		return;
	}

	int idx = s + 1;

	while (idx < e)
	{
		if (v[s] < v[idx]) // idx : 부모보다 큰 오른쪽 노드 
			break;
		idx++;
	}

	solve(s + 1, idx); // 왼쪽 자식 노드 방문
	solve(idx, e); // 오른쪽 자식 노드 방문
	cout << v[s] << '\n'; // 부모 노드 방문
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> n)
		v.push_back(n);

	solve(0, v.size());
	return 0;
}