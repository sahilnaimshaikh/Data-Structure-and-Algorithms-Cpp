/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 10^4
s and p consist of lowercase English letters.
*/

#include<bits/stdc++.h>
using namespace std;

bool validAnagram(string sub, unordered_map<char,int> mapp){
    for(auto it : sub){
        if(mapp.find(it) == mapp.end() || mapp[it] == 0)return false;
        else mapp[it]--;
    }
    for(auto it : mapp){
        if(it.second > 0)return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> mapp;
        for(auto it : p){
            mapp[it]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if(validAnagram(s.substr(i, p.size()), mapp))ans.push_back(i);
        }
        
        return ans;

    }           
            
int main(){
            
     string s = "abbab";
     string p = "ab";
     for(auto it : findAnagrams(s,p)) cout<<it<<" ";
            
return 0;
}

// above given solution is the brute force solution which is working fine for medium size arrays. And giving TLE on leetcode for large size of strings.