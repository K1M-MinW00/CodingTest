#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {

    bool condition1 = false;
    bool condition2 = false;
    
    int gcd_A= arrayA[0], gcd_B=arrayB[0];
    
    for(int i=1;i<arrayA.size();++i)
        gcd_A = gcd(gcd_A,arrayA[i]);
    
    for(int i=1;i<arrayB.size();++i)
        gcd_B = gcd(gcd_B,arrayB[i]);
    
    
    for(int i = 0;i<arrayB.size();++i)
    {
        if(arrayB[i]%gcd_A == 0)
        {
            condition1 = true;
            break;
        }
    }
    
  
    
    for(int i=0;i<arrayA.size();++i)
    {
        if(arrayA[i]%gcd_B ==0)
        {
            condition2= true;  
            break;
        }
    }
   
    if(condition1 && condition2)
        return 0;
    else if(condition1 && !condition2)
        return gcd_B;
    else if(condition2 && !condition1)
        return gcd_A;
    else
        return max(gcd_A,gcd_B);
    
}