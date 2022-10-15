
#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {

        string answer;
        for(int i = 0; i < s.size(); i++){
            if(iswalnum(s[i])){
                answer.push_back(tolower(s[i]));
            }
        }
        if(answer.size() == 0) return true;
        
        cout<<answer;
        for(int i = 0 ; i <= answer.size()/2; i++){
            if(answer[i] != answer[answer.size()-i-1])return false;
        }
        
        return true;
    }
};
// @lc code=end

