#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std; 
bool isDivisible(int x)
{
    if (x<0) return false; 
    for ( int y=1; y<=20; ++y)
    {
      if (x%y !=0)
       return false;
    }
  return true;
}
int main() {
 int a=1;
 cin >> a; 
 vector<int>Number;
 for(int i=a; ; ++i)
{
  if (isDivisible(i))
 { 
   Number.push_back(i);
   break;
 }
}

  int minVal= *min_element(Number.begin(),Number.end());
  cout << minVal << endl;
return 0; 
}
