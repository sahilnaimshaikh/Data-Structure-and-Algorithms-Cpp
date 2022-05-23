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
          if(freq.find(s[r]) != freq.end()) {
              l = max(freq[s[r]]+1, l);
          }
          freq[s[r]] = r;
          len = max(len, r-l+1);
          r++;
       }
       
        return len;
    }      
};
          
int main(){

    string s = "sahilshaikh";
    Solution sol;
   
    cout<<sol.lengthOfLongestSubstring(s);      
    
          
          
return 0;
}