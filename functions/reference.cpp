#include<bits/stdc++.h>
using namespace std;
            
            
int main(){
            
        int a  = 9;
        int & b = a;
        b--;
        int & c = b;
        c--;
        cout<<a;  
return 0;
}