/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

*/

#include<bits/stdc++.h>
using namespace std;
 bool isAnagram(string s, string t) {
       unordered_map<char, int> mapp;
        for(int i = 0; i < s.size(); i++){
            mapp[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(mapp.find(t[i]) == mapp.end() || mapp[t[i]] == 0)return false;
            else{
                mapp[t[i]]--;
            }
        }
         for(int i = 0; i < s.size(); i++){
            if(mapp[s[i]] > 0)return false;
        }
        return true;
    }            
            
int main(){
            
    string s= "sahil";
    string t = "lihasa";
    cout<<isAnagram(s, t);    
            
return 0;
}