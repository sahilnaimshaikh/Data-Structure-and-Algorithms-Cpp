#include <bits/stdc++.h>
using namespace std;
void display(vector<int> myVector)
{

    for (auto it : myVector)
    {
        cout << it << " ";
    }
    cout << endl;
}

int removeDuplicates(vector<int> &nums)
{
    int counter = 1;
    int element = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
       if(nums[i]>element){
           nums[counter] = nums[i];
           counter++;
           element = nums[i];
       }
    }
    return counter;
}
int main()
{

    vector<int> arr = {1, 1, 2, 2, 3, 4, 5, 5, 6, 6};
    display(arr);
    removeDuplicates(arr);
    display(arr);
    return 0;
}