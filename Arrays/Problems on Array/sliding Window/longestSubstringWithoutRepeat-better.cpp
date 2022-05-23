// Optimal Approach
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int lengthOfLongestSubstring(string s) {
       int l = 0, r = 0;
       int len=0;
       map<char,int> freq;
       while (r<s.size())
       {
         if(freq.find(s[r]) != freq.end()){
             freq.erase(freq.find(s[l]));
             l++; // in this approach we are incrementing l only by one , in worst case it does increases the complexity
             break;
         }
         freq[s[r]] = r;
         len = max(len, r-l+1);
         r++;
       }
       
        return len;
    }      
};
          
int main(){

    string s = "sailhh";
    Solution sol;
   
    cout<<sol.lengthOfLongestSubstring(s);      
    
          
          
return 0;
}