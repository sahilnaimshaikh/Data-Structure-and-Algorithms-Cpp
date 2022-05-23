#include<bits/stdc++.h>
using namespace std;
               
 vector<int> plusOne(vector<int>& digits) {
       bool trigger = false; 
       int breakPoint;
     for (int i = digits.size()-1; i >= 0 ; i--)
     {
         if(digits[i] != 9) {
              trigger = true;
              breakPoint = i;
              break;
         }
     }
     if(trigger){
         if(breakPoint == digits.size()-1){
        digits[digits.size()-1] = digits[digits.size()-1]+1;
         }
         else{
             digits[breakPoint] = digits[breakPoint]+1; 
             for (int  i = breakPoint+1; i < digits.size(); i++)
             {
                digits[i] = 0;
             }
             
         }
     }
     else{
         digits.emplace_back(9);
         digits[0] = 1;
         for (int  i = 1; i < digits.size(); i++)
         {
            digits[i] = 0;
         }
         
     }

    return digits;

    }          
          
int main(){

  vector<int> digits = {1,0,0,1};        
  for(auto it : plusOne(digits)) cout<<it<<" ";  
          
          
return 0;
}