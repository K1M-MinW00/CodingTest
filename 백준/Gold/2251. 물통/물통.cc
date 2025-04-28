#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 201

int A, B, C;
bool visited[MAX][MAX][MAX];

set<int> s;

struct t { int a, b, c; };

void solve()
{
	queue<t> q;
	q.push({ 0,0,C });

	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;

		q.pop();

		if (visited[a][b][c])
			continue;

		visited[a][b][c] = true;

		if (a == 0)
			s.insert(c);

		// A -> B
		if (a + b > B)
			q.push({ a + b - B,B,c });
		else
			q.push({ 0,a + b,c });

		// A -> C
		if (a + c > C)
			q.push({ a + c - C,b,C });
		else
			q.push({ 0,b,a + c });

		// B -> A
		if (a + b > A)
			q.push({ A,a + b - A,c });
		else
			q.push({ a + b,0,c });

		// B -> C
		if (b + c > C)
			q.push({ a,b + c - C,C });
		else
			q.push({ a,0,b + c });

		// C -> A
		if (a + c > A)
			q.push({ A,b,a + c - A });
		else
			q.push({ a + c,b,0 });

		// C -> B
		if (b + c > B)
			q.push({ a,B,b + c - B });
		else
			q.push({ a,b + c,0 });
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;

	solve();

	for (int e : s)
		cout << e << ' ';

	return 0;
}