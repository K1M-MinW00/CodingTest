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

#define MAX 10000001

using namespace std;
long long k;
bool p[MAX];

void isPrime()
{
	for (long long i = 2; i * i < MAX; ++i)
	{
		if (p[i])
		{
			for (long long j = i * i; j < MAX; j += i)
				p[j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k;

	memset(p, true, MAX);

	isPrime();

	long long idx = 2;
	long long cnt = 0;

	while (1)
	{
		if (p[idx] == true)
			cnt++;

		if (cnt == k)
			break;
		idx++;
	}

	cout << idx;
	return 0;
}