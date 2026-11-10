#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string str_a = to_string(a);
    string str_b = to_string(b);
    
    string temp_1 = str_a + str_b;
    string temp_2 = str_b + str_a;
    
    int ans1 = stoi(temp_1);
    int ans2 = stoi(temp_2);
    
    answer = max(ans1,ans2);
    
    return answer;
}