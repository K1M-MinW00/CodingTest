#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool isVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string str;
		cin >> str;
		if (str == "end")
			break;

		bool Vowel = false;
		bool Triple = false;
		bool Double = false;
		int ccnt = 0, vcnt = 0, prev = -1;


		for (int i = 0; i < str.length(); ++i)
		{
			int idx = str[i];

			if (isVowel(idx))
			{
				ccnt = 0;
				vcnt++;
				Vowel = true;
			}
			else
			{
				vcnt = 0;
				ccnt++;
			}

			if (ccnt == 3 || vcnt == 3)
			{
				Triple = true;
				break;
			}

			if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o'))
			{
				Double = true;
				break;
			}
			prev = idx;
		}

		cout << '<' << str << '>' << ' ';
		if (Vowel && !Double && !Triple)
			cout << "is acceptable.\n";
		else
			cout << "is not acceptable.\n";
	}

	return 0;
}