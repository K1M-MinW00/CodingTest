#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<string,int,int,string> t;

t to_data(string& str)
{
    t result;
    string head,s_number;
    int idx;
    
    for(idx = 0;idx<str.size();++idx)
    {
        if(str[idx] >= 65 && str[idx] <= 90) 
            head += str[idx];
        
        else if(str[idx] >= 97 && str[idx] <= 122)
            head += str[idx] - 32; // lower -> upper
        
        else if(str[idx] == ' ' || str[idx] == '-' || str[idx] == '.')
            head += str[idx];
        else if(str[idx] >= 48 && str[idx] <= 57) // head 끝
            break;
        
    }
    
    for(idx;idx<str.length();++idx)
    {
        if(str[idx] >= 48 && str[idx] <= 57)
            s_number += str[idx];
        
        else // number 끝
            break;
    }
    
    get<0>(result) = head;
    get<1>(result) = stoi(s_number);
    get<2>(result) = 0;
    get<3>(result) = str;
    
    return result;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<t> info;
    
    for(int i=0;i<files.size();++i)
    {
        t tmp = to_data(files[i]);
        get<2>(tmp) = i;
        info.push_back(tmp);
    }
    
    sort(info.begin(),info.end()); // head -> number -> idx 기준으로 정렬
    
    for(int i=0;i<info.size();++i)
    { 
        string file = get<3>(info[i]); 
        answer.push_back(file);
    }
    
    return answer;
}