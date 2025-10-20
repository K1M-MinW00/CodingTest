#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);

	int idx = 0;
	for (int i = 0; i < my_string.length(); ++i)
	{
		char c = my_string[i];

		if (isupper(c))
			idx = c - 'A';
		else
			idx = c - 'a' + 26;
		answer[idx]++;
	}
    
    return answer;
}