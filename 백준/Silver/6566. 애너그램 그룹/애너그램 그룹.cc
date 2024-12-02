#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string,priority_queue<string,vector<string>,greater<string>>> m;

struct cmp {
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		if (a.first == b.first)
			return m[a.second].top() > m[b.second].top();

		return a.first < b.first;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s,temp;
	while (1)
	{
		cin >> s;
		if (cin.eof() == true)
			break;
		temp = s;

		sort(temp.begin(), temp.end());
		
		if (m.find(temp) != m.end())
		{
			m[temp].push(s);
		}
		else
		{
			priority_queue<string, vector<string>, greater<string>> pq;
			m.insert({ temp,pq });
			m[temp].push(s);
		}
	}

	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

	for (auto e : m)
	{
		pq.push({ e.second.size(),e.first });
	}

	int size = pq.size();

	if (size > 5)
		size = 5;

	for (size; size >= 1; size--)
	{
		string cur = pq.top().second;
		pq.pop();
		cout << "Group of size " << m[cur].size() << ": ";
		
		string before;
		while (!m[cur].empty())
		{
			if(before != m[cur].top())
				cout << m[cur].top() << ' ';
			before = m[cur].top();
			m[cur].pop();
		}
		cout << "." << '\n';
	}
	return 0;
}