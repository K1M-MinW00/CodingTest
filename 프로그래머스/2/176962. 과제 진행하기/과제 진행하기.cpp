#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

inline int time2int(string time)
{
    return ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + (time[3] - '0') * 10 + (time[4] - '0');
}

typedef tuple<int, int, string> t;

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;

    int n = plans.size();
    vector<t> v(n);

    for (int i = 0; i < n; ++i)
    {
        int t1 = time2int(plans[i][1]);
        int t2 = stoi(plans[i][2]);
        v[i] = { t1, t2, plans[i][0] };
    }

    sort(v.begin(), v.end()); // 시작 시간 기준 정렬

    /*
    for (int i = 0; i < n; ++i)
        cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << endl;
    cout << endl;
    */

    stack<t> ing;

    int idx = 0;
    t cur, next,stop;
    int time = get<0>(v[0]);
    int cur_end, next_start;

    bool update = false;

    for (int i = 0; i < n -1;)
    {
        if(update == false)
            cur = v[i];
        next = v[i + 1];
        update = false;
        if (time + get<1>(cur) == get<0>(next))
        {
            answer.push_back(get<2>(cur));
            time += get<1>(cur);
            ++i;
        }
        else if (time + get<1>(cur) > get<0>(next))
        {
            get<1>(cur) -= get<0>(next) - time;
            ing.push(cur);
            time = get<0>(next);
            ++i;
        }
        else // time + get<1>(cur) < get<0>(next)
        {
            answer.push_back(get<2>(cur));
            time += get<1>(cur);
            
            if (ing.empty())
            {
                time = get<0>(next);
                ++i;
            }
            else
            {
                cur = ing.top();
                ing.pop();
                update = true;
            }
        }

        if (i == n - 1)
            answer.push_back(get<2>(next));
    }

    while (ing.size())
    {
        cur = ing.top();
        ing.pop();

        answer.push_back(get<2>(cur));
    }

    

    return answer;
}