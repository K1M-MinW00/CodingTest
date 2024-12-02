#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> v1 = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
vector<string> v2 = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
unordered_map<char, int> v3 = { {'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1} };

int rome2arab(string s)
{
	int result = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		if (i < s.length() - 1 && v3[s[i]] < v3[s[i + 1]])
			result -= v3[s[i]];
		else
			result += v3[s[i]];
	}
	return result;
}

string arab2rome(int n)
{
	string result;

	int idx = 0;

	while (n)
	{
		if (n / v1[idx] > 0)
		{
			int q = n / v1[idx];
			n %= v1[idx];
			for (int i = 0; i < q; ++i)
				result += v2[idx];
		}
		idx++;
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string input;
	int num;
	while (n--)
	{
		cin >> input;

		if (input[0] >= '0' && input[0] <= '9')
		{
			num = stoi(input);
			cout << arab2rome(num) << '\n';
		}
		else
			cout << rome2arab(input) << '\n';
	}

	return 0;
}