#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x)
{
	q.push(x);
}

int pop()
{
	if (q.empty())
		return -1;

	int x = q.front();
	q.pop();

	return x;
}

int size()
{
	return q.size();
}

int empty()
{
	if (q.size())
		return 0;
	else
		return 1;
}

int front()
{
	if (q.size())
		return q.front();
	else
		return -1;
}

int back()
{
	if (q.size())
		return q.back();
	else
		return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;


	string op;
	int x;
	while (n--)
	{
		cin >> op;

		if (op == "push")
		{
			cin >> x;
			push(x);
		}
		else if (op == "pop")
			cout << pop() << '\n';
		else if (op == "size")
			cout << size() << '\n';
		else if (op == "empty")
			cout << empty() << '\n';
		else if (op == "front")
			cout << front() << '\n';
		else if (op == "back")
			cout << back() << '\n';

	}

	return 0;
}