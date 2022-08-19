#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> arry){
    int x = 0;
    for(int i = 0; i< arry.size(); i++){
        x = x^arry[i];
    }
    return x;
}            
            
int main(){
            
        vector<int> arry = {11,32,21,32,11};
         cout<<singleNumber(arry);   
return 0;
}