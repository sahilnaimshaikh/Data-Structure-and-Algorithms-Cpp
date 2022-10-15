#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    if(num == 1)return false;
    if(num == 2 || num == 3){
        return true;
    }
    for(int i = 5; i <= sqrt(num); i = i+6){
        cout<<"*"<<" ";
        if(num%i == 0 || num%(i+2)==0){
            return false;
        }
    }
    return true;

}
       
            
int main(){
            
        int num = 22367;
        cout<<"Square root of given num is "<<sqrt(num)<<endl;
    if(isPrime(num))cout<<"It is a Prime"<<endl;
    else cout<<"It is not a Prime"<<endl;
            
return 0;
}

// 36 -> (2,18),(3,12),(4,9),(6,6)
//        (2,3,4,6)