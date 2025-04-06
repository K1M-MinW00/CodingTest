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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string car;
	queue<string> q;
	set<string> str;
	set<string> pass;

	int answer = 0;

	for (int i = 0; i < 2 * n; ++i)
	{
		cin >> car;

		if (str.find(car) == str.end()) // 입차
		{
			q.push(car);
			str.insert(car);
		}
		else // 출차
		{
			string front;

			while (1)
			{
				front = q.front();

				if (pass.find(front) == pass.end())
				{
					break;
				}
				else // 이미 빠져나간 차
				{
					pass.erase(front);
					q.pop();
				}
			}
			if (front == car) // 정상 출차
			{
				q.pop();
				str.erase(car);
			}
			else
			{
				pass.insert(car);
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
}