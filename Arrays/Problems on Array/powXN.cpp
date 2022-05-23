#include<bits/stdc++.h>
using namespace std;
               
 double myPow(double x, int n) {
     double ans = 1;
     long long nn = n;
     if(nn<0) nn = -1*nn;
     while(nn){
     if(nn%2==1){
         ans = ans *x;
         nn--;
     }
     else {
         x = x*x;
         nn/=2;
     }
     }
     if(n<0) ans = (double)(1.0)/(double)(ans);
     return ans;
}          
          
int main(){
          
double x = 2.00;
int n = -10;
cout<<myPow(x,n);        
          
          
return 0;
}