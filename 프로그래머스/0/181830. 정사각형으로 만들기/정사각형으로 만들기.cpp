#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int r = arr.size();
    int c = arr[0].size();
    
    if(r==c)
        return arr;
    
    else if(r>c)
    {
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<r-c;++j)
                arr[i].push_back(0);
        }
    }
    
    else
    {
        for(int i=r;i<c;++i)
        {
            vector<int> v(c,0);
            arr.push_back(v);
        }
    }
    return arr;
}