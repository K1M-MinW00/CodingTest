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
#include <bitset>
#include <tuple>
using namespace std;
#define N 100005

int n;

struct t
{
	string name;
	int ko, en, ma;
};

bool cmp(t a, t b)
{
	if (a.ko == b.ko && a.en == b.en && a.ma == b.ma)
		return a.name < b.name;

	if (a.ko == b.ko && a.en == b.en)
		return a.ma > b.ma;

	if (a.ko == b.ko)
		return a.en < b.en;

	return a.ko > b.ko;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	vector<t> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; ++i)
	{
		cout << v[i].name << '\n';
	}

	return 0;
}