#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> uom;

vector <pair<int, string >> m;

int str_int(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		if (i < a.length() - 1 && uom[a[i]] < uom[a[i + 1]])
		{
			sum -= uom[a[i]];
		}
		else
			sum += uom[a[i]];
	}
	return sum;
}

string int_str(int a)
{
	string answer;

	for (int i = 0; i < m.size(); i++)
	{
		while (a >= m[i].first)
		{
			answer += m[i].second;
			a -= m[i].first;
		}
	}

	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;


	uom.insert({ 'I',1 });
	uom.insert({ 'V',5 });
	uom.insert({ 'X',10 });
	uom.insert({ 'L',50 });
	uom.insert({ 'C',100 });
	uom.insert({ 'D',500 });
	uom.insert({ 'M',1000 });


	int sum = 0;

	sum += str_int(a);
	sum += str_int(b);

	cout << sum << '\n';

	m.push_back({ 1000,"M" });
	m.push_back({ 900,"CM" });
	m.push_back({ 500,"D" });
	m.push_back({ 400,"CD" });
	m.push_back({ 100,"C" });
	m.push_back({ 90,"XC" });
	m.push_back({ 50,"L" });
	m.push_back({ 40,"XL" });
	m.push_back({ 10,"X" });
	m.push_back({ 9,"IX" });
	m.push_back({ 5,"V" });
	m.push_back({ 4,"IV" });
	m.push_back({ 1,"I" });

	cout << int_str(sum);

	return 0;
}