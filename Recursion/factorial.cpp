#include<bits/stdc++.h>
using namespace std;

     int factorial(int number){
         if(number==0) return 1;
         return number*factorial(number-1);
     }       
            
int main(){
            
        int number;
        cout<<"Enter number to find the factorial:";
        cin>>number;
        cout<<"Factorial is : "<<factorial(number);
            
return 0;
}