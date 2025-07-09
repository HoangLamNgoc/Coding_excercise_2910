#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 
bool isPralinedromic(int x)
{
    if (x<0) return false; 
    int y=x;
    int d=0;
    if (x>0)
    { 
        while (x>0)
        {
            int c=x%10;
            d= d*10+c;
            x=x/10;
        }
    }
    return y == d; 
}


int main() {
 int a,b;
 cin >> a >> b  ; 
 vector<int> PralinefromicNumber; 
 for (a=100;a<=1000;++a)
 {  for(b=100;b<=1000;++b)
     {
        int i = a * b ;
        if(isPralinedromic(i))
            PralinefromicNumber.push_back(i);
     }
 }
   int max= *max_element( PralinefromicNumber.begin(), PralinefromicNumber.end());
cout << max << endl; 
    return 0 ;
}
