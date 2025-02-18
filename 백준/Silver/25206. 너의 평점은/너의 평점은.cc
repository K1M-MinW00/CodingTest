#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

map<string, float> m = { {"A+",4.5},{"A0",4.0},{"B+",3.5},{"B0",3.0},{"C+",2.5},{"C0",2.0},{"D+",1.5},{"D0",1.0},{"F",0.0} };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string name, grade;
	float score;

	float total = 0;
	int cnt = 0;
	for (int i = 0; i < 20; ++i)
	{
		cin >> name >> score >> grade;

		if (grade == "P")
			continue;

		cnt += score;
		total += score * m[grade];
	}

	cout << total / cnt;

	return 0;
}