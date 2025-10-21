#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<vector<string>> s;

bool check(string a, string b)
{
	if (a.length() != b.length())
		return false;

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i] || b[i] == '*')
			continue;
		else
			return false;
	}
	return true;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	int answer = 0;

	sort(user_id.begin(), user_id.end());

	do
	{
		vector<string> temp;

		for (int i = 0; i < banned_id.size(); i++)
		{
			if (check(user_id[i], banned_id[i]))
			{
				temp.push_back(user_id[i]);
			}
		}

		if (temp.size() == banned_id.size())
		{
			sort(temp.begin(), temp.end());
			s.insert(temp);
		}

	} while (next_permutation(user_id.begin(), user_id.end()));

	answer = s.size();
	return answer;
}