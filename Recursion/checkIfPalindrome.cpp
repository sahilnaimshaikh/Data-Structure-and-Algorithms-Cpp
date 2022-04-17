#include<bits/stdc++.h>
using namespace std;

   void checkIfPalindrome(string s, int i, int n){

       if(i>=n/2){
           cout<<"String is palindrome";
           return;
       }
        if(s[i] == s[n-i-1]) checkIfPalindrome(s, i+1, n);
        else{
            cout<<"String is not palindrome";
            return;
        }
   }         
            
int main(){
            
        string s = "1010101";
        int n = s.size();
        checkIfPalindrome(s, 0, n);
            
return 0;
}