#include <string>
#include <vector>

using namespace std;

int GCD(int a,int b)
{
   if(a < b)
   {
       int temp = a;
       a = b;
       b = temp;
   }
    
    if(a % b == 0)
        return b;
    
    return GCD(b,a%b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int denom = denom1 * denom2;
    int num = numer1 * denom2 + numer2 * denom1;
    
    int gcd = GCD(denom,num);
    answer.push_back(num/gcd);
    answer.push_back(denom/gcd);
    return answer;
}