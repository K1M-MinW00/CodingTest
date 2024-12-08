#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    
    int a[26] = {0};
    
    for(int i=0;i<s.length();++i)
        a[s[i]-'a']++;
    
    for(int i=0;i<26;++i)
        cout << a[i] << ' ';
    
    return 0;
}