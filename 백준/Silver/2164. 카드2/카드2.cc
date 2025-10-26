#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;

int main()
{
    cin >> n;
    queue<int> arr;
    for(int i=1;i<=n;i++)
        arr.push(i);

    while(arr.size()>1)
    {
        arr.pop();
        arr.push(arr.front());
        arr.pop();
    }

    cout << arr.front();
    return 0;
}