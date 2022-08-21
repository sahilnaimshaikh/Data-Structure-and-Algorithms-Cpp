/* Letter Case Permutation
Medium

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.



Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]


Constraints:

1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.

*/

#include <bits/stdc++.h>
using namespace std;

void permute(int i, string st, string ans, vector<string> &answer)
{
    if (i == st.size())
    {
        answer.push_back(ans);
        return;
    }

    if (!isalpha(st[i]))
    {
        ans.push_back(st[i]);
        permute(i + 1, st, ans, answer);
    }
    else
    {
        ans.push_back(tolower(st[i]));
        permute(i + 1, st, ans, answer);

        ans.pop_back();
        ans.push_back(toupper(st[i]));
        permute(i + 1, st, ans, answer);
    }
}

int main()
{

    string st = "a1b2";
    string ans = "";
    vector<string> answer;
    permute(0, st, ans, answer);
    for (auto it : answer)
        cout << it << " ";

    return 0;
}