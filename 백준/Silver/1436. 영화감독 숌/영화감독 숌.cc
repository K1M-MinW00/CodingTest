#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int target = 665;
	string temp;

	for (int i = 0; i < n; ++i)
	{
		while (1)
		{
			target++;
			temp = to_string(target);
			if (temp.find("666") != string::npos) // string::npos = 찾는 문자가 없는 경우
				break;
		}
	}
	cout << target;

	return 0;
}