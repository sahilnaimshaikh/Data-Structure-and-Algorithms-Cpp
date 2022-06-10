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
    int element = nums[0];
    int counter = 1;
    for (int j = 0; j < nums.size(); j++)
    {
        if(element != nums[j]){
           element = nums[j];
           nums[counter] = nums[j];
           counter++;
        }
    }
    return counter;
    
}
// int removeDuplicates(vector<int> &nums)
// {
//     int counter = 1;
//     int element = nums[0];
//     for (int i = 0; i < nums.size(); i++)
//     {
//        if(nums[i]>element){
//            nums[counter] = nums[i];
//            counter++;
//            element = nums[i];
//        }
//     }
//     return counter;
// }
int main()
{

    vector<int> arr = {0,0,1,1,1,1,2,3,3};
    display(arr);
    removeDuplicates(arr);
    display(arr);
    return 0;
}