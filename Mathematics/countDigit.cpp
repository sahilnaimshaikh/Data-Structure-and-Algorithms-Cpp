#include<bits/stdc++.h>
using namespace std;
            
int countDigits(int number){
    return floor(log10(number)+1);
    //we know that log10 gives us a answer which means that , that answer is the maximum number division of the input number by 10 until it reaches below 0.

    //seedhi baat log10 ek input int ke kitni baar 10 equal tukde kar sakte hai jabtak vo less than equals to zero na ho jaye, vo return karta hai.
}
int main(){
            
        int number = 1478254887;
        cout<<countDigits(number);
            
return 0;
}