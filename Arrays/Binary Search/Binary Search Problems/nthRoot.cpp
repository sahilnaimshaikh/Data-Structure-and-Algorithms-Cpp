#include<bits/stdc++.h>
using namespace std;
double midRaiseToN(double mid, int n){
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * mid;
    }
    // cout<<result<<endl;
    return result;
}

double getNthRoot(int n, int m){
    double low = 1.0;
    double high = m;
    double e = 1e-6;
    double mid;

    while((high-low)>e){

        mid = (high+low)/2.0;
        if (midRaiseToN(mid,n)>m)
        {
            high = mid;
        }
        else{
            low = mid;
        }
    }
    // cout<<low<<" "<<high<<endl;
    return mid;
}      
            
int main(){
            
        int n,m;
        cin>>n>>m;
        cout<<getNthRoot(n,m);
            
return 0;
}