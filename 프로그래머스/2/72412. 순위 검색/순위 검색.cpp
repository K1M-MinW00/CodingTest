#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> d[3][2][2][2];

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    string token;
    int v1, v2, v3, v4, score; // cpp,java,python : 0,1,2 / backend,frontend : 0,1 / junior,senior : 0,1 / chicken,pizza : 0,1

    for (int j = 0; j < info.size(); j++)
    {
        istringstream sss(info[j]);
        getline(sss, token, ' ');
        if (token == "cpp") v1 = 0; else if (token == "java") v1 = 1; else v1 = 2;

        getline(sss, token, ' ');
        if (token == "backend") v2 = 0; else v2 = 1;

        getline(sss, token, ' ');
        if (token == "junior") v3 = 0; else v3 = 1;

        getline(sss, token, ' ');
        if (token == "chicken") v4 = 0; else v4 = 1;

        getline(sss, token, ' ');
        score = stoi(token);

        d[v1][v2][v3][v4].push_back(score);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    sort(d[i][j][k][l].begin(), d[i][j][k][l].end());

    for (int q = 0; q < query.size(); q++)
    {
        istringstream sss(query[q]);

        getline(sss, token, ' ');
        if (token == "-")
            v1 = -1;
        else if (token == "cpp")
            v1 = 0;
        else if (token == "java")
            v1 = 1;
        else if(token == "python")
            v1 = 2;
        // cout << token << ' ';

        getline(sss, token, ' '); // and
        getline(sss, token, ' ');
        if (token == "-")
            v2 = -1;
        else if (token == "backend")
            v2 = 0;
        else if(token=="frontend")
            v2 = 1;
        // cout << token << ' ';

        getline(sss, token, ' '); // and
        getline(sss, token, ' ');
        if (token == "-")
            v3 = -1;
        else if (token == "junior")
            v3 = 0;
        else if(token =="senior")
            v3 = 1;
        // cout << token << ' ';

        getline(sss, token, ' '); // and
        getline(sss, token, ' ');
        if (token == "-")
            v4 = -1;
        else if (token == "chicken")
            v4 = 0;
        else if(token =="pizza")
            v4 = 1;
        // cout << token << ' ';

        getline(sss, token, ' ');
        if (token == "-")
            score = -1;
        else
            score = stoi(token);

        // cout << v1 << ' ' << v2 << ' ' << v3 << ' ' << v4 << ' ' << score << endl;

        int cnt = 0;

        for (int i = 0; i < 3; i++)
        {
            if (v1 != -1 && v1 != i)
                continue;
            for (int j = 0; j < 2; j++)
            {
                if (v2 != -1 && v2 != j)
                    continue;
                for (int k = 0; k < 2; k++)
                {
                    if (v3 != -1 && v3 != k)
                        continue;
                    for (int l = 0; l < 2; l++)
                    {
                        if (v4 != -1 && v4 != l)
                            continue;
                        auto low = lower_bound(d[i][j][k][l].begin(), d[i][j][k][l].end(), score);
                        for (; low != d[i][j][k][l].end(); ++low) cnt++;
                           
                    }
                }
            }
        }
        answer.push_back(cnt);
    }

    // for (int i = 0; i < answer.size(); i++)
    //     cout << answer[i] << ' ';
    return answer;
}