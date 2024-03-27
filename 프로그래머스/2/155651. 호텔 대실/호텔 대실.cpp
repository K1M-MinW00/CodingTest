#include <algorithm>
#include <vector>
using namespace std;

int time2int(string &str)
{
    int time = ((str[0]-'0')*10 + str[1]-'0') * 60 + (str[3]-'0')*10 + (str[4]-'0');

    return time;
}
    
typedef pair<int,int> t;

int solution(vector<vector<string>> book_time) {
    
    int answer = 0;
    int n = book_time.size();
    
    vector<t> book(n);
    vector<vector<t>> room;
    
    for(int i=0;i<n;i++)
    {
        int start = time2int(book_time[i][0]);
        int end = time2int(book_time[i][1]) + 10; // 청소 시간 10분 포함
        
        book[i] = {start,end};
    }
    
    sort(book.begin(),book.end()); // 입실 시간 기준 오름차순 정렬
    
    for(auto& b : book)
    {
        bool isEmpty = false; // 방이 비어있는지
        
        for(auto& r : room)
        {
            if(r.back().second <= b.first) // room 의 가장 마지막 퇴실 시간이 b 입실 이후
            {
                isEmpty = true;
                r.push_back(b);
                break;
            }
        }
        
        if(isEmpty == false) // 방이 다 차있다면
        {
            vector<t> tmp(1,b);
            room.push_back(tmp);
        }
    }
    
    answer = room.size();
    return answer;
}