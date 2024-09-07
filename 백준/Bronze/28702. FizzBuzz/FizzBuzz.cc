#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	int num;
	for (int i = 0; i < 3; ++i)
	{
		cin >> input;

		if (input[0] >= '1' && input[0] <= '9')
		{
			int temp = stoi(input);
			num = temp + (3 - i);
		}



	}

	string answer;

	if (num % 3 == 0 && num % 5 == 0)
		answer = "FizzBuzz";
	else if (num % 3 == 0)
		answer = "Fizz";
	else if (num % 5 == 0)
		answer = "Buzz";
	else
		answer = to_string(num);

	cout << answer;
}