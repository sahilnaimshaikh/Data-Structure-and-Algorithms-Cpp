#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int reverse(int x) {
         long long int n;
         if(x<0) n = -1*x;
         else n = x;
        long long int s = 0;
        while(n>0){
            int r = n%10;
            s = (s*10)+r;
            n/=10;
        }
        if(x<0) return -1*s;
        else  return s;
    }      
};
          
int main(){
    long long int x = 15236554789;
    Solution sol;
    cout<<sol.reverse(x);      
    
          
          
return 0;
}
// this solution is giving the runtime error... int overflow is happening 