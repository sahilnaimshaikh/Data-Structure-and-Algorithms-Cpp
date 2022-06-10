#include <bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};


class Solution
{
public:

    bool comparator(meeting m1, meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        meeting meet[n];
        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }
        sort(meet, meet + n, comparator);

        vector<int> answer;
        answer.push_back(meet[0].pos);
        int limit = meet[0].end;
        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > limit)
            {
                limit = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }
        return answer.size();
    }
};

int main()
{

    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    Solution sol;
    cout << sol.maxMeetings(start, end, n);

    return 0;
}