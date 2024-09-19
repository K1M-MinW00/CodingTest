#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string temp = "";
    int n;
    
    vector<int> num;
    for(int i=0;i<s.length();++i)
    {
        if(s[i] == ' ')
        {
            n = stoi(temp);
            num.push_back(n);
            temp = "";
        }
        else
            temp += s[i];
    }
    
    n = stoi(temp);
    num.push_back(n);
    
    sort(num.begin(),num.end());
    
    answer += to_string(num[0]) + " " + to_string(num.back());
    return answer;
}