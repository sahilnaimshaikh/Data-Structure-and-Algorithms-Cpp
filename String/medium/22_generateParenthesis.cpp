/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include<bits/stdc++.h>
using namespace std;

 void generate(int open, int close, string  ans, vector<string> & answer){
  
        if(open ==0 && close == 0){
            answer.push_back(ans);
            return;
        }
        
        if(open == 0){
            ans.push_back(')');
            generate(open, close-1, ans, answer);
            
            return;
        }
        
        if(open == close){
            ans.push_back('(');
            generate(open-1, close, ans, answer);
        }
        
        if(open < close){
            ans.push_back('(');
            
            generate(open-1, close, ans, answer);
            
            ans.pop_back();
            
            ans.push_back(')');
            generate(open, close-1, ans, answer);
            
            
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string ans; 
        generate(n, n, ans, answer);
        return answer;
    }    
            
int main(){

for(auto it : generateParenthesis(8))cout<<it<<" ";
        
            
return 0;
}