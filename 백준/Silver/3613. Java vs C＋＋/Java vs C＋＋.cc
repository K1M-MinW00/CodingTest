#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

string c2java()
{
	string answer = v[0];;

	for (int i = 1; i < v.size(); ++i)
	{
		string temp = v[i];
		temp[0] = toupper(v[i][0]);
		answer += temp;
	}

	return answer;
}

string java2c()
{
	string answer = v[0];

	for (int i = 1; i < v.size(); ++i)
	{
		string temp = v[i];
		temp[0] = tolower(v[i][0]);
		answer += "_" + temp;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	if (s[0] == '_' || s.back() == '_') // 시작과 끝이 _ 인 경우, Error
	{
		cout << "Error!";
		return 0;
	}

	string temp;
	bool c = false;
	bool java = false;
	bool error = false;



	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '_')
		{
			c = true;
			if (temp != "")
			{
				v.push_back(temp);
				temp = "";
			}
			else
			{
				error = true;
				break;
			}
		}

		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			java = true;
			if (temp != "")
			{
				v.push_back(temp);
			}
			else
			{
				error = true;
				break;
			}
			temp = s[i];
		}

		else if (s[i] >= 'a' && s[i] <= 'z')
			temp += s[i];
	}

	if (temp != "")
		v.push_back(temp);


	if (error || (c && java))
		cout << "Error!";
	else if (c)
		cout << c2java();
	else if (java)
		cout << java2c();
	else
		cout << temp;
	
	return 0;
}