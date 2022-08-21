/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.



Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".


Constraints:

1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.

*/

#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part)
{

    // for keeping the track of last occurence of the part[0]
    bool flag = false;
    int lastInd = -1;

    // iterating in string s
    int i = 0;
    while (i < s.size())
    {
        int j = 0;
        // at any index of s, if we find the starting character of substring we will check whether it is forming a substring or not.
        if (s[i] == part[j])
        {

            if (i + part.size() - 1 < s.size() && s.substr(i, part.size()) == part)
            {
                // if it is a substring then we will erase it from the s
                s.erase(s.begin() + i, s.begin() + i + part.size());
                if (flag)
                    i = lastInd - 1;
                else
                    i--;
            }
            else
            {

                if (lastInd == -1)
                {
                    lastInd = i;
                    flag = true;
                }
            }
        }
        i++;
    }
    return s;
}

// more simple and concise solution, dryrun to understand;
string removeOccurrences(string s, string part)
{
    string x = s;
    int n = s.size(), m = part.size(), i, j;
    for (i = 0, j = 0; i < n; i++)
    {
        x[j++] = s[i];
        if (j >= m && x.substr(j - m, m) == part)
            j -= m;
    }
    return x.substr(0, j);
}

int main()
{

    string s = "aabbc";
    string part = "ab";
    cout << removeOccurrences(s, part);

    return 0;
}