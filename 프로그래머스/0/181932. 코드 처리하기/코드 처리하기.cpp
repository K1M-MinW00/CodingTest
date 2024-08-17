#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool mode = false; // mode : false = 0 , true = 1;
    
    for(int i=0;i<code.length();++i)
    {
        char c = code[i];
        
        if(c == '1')
        {
            mode = !mode;
            continue;
        }
        else
        {
            if(mode)
            {
                if(i % 2 == 1)
                    answer.push_back(code[i]);
            }
            else
            {
                if(i % 2 == 0)
                    answer.push_back(code[i]);
            }
        }        
    }
    
    if(answer == "")
        answer = "EMPTY";

    return answer;
}