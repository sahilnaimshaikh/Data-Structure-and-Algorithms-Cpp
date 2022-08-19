#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    void gen(string s, int index, vector<string> &ds, vector<vector<string>> &result){
        if(index == s.size()){
            result.push_back(ds);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index,i-index+1));
                gen(s, i+1, ds, result);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
       vector<string> ds;
       vector<vector<string>> result;
       gen(s, 0, ds, result); 
       return result;
    }     
};
          
int main(){
          
    string s = "aabb";
   Solution sol;
   for(auto it: sol.partition(s)){
       for(auto i: it)cout<<i<<" ";
       cout<<endl;
   }
          
          
return 0;
}