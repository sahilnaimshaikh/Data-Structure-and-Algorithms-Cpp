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
int removeElement(vector<int> &nums, int val)
{
    int counter = 0;
    int max = *max_element(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]==val){
            nums[i] = max+1;
            counter++;
        }
    }
    sort(nums.begin(),nums.end());
    return (nums.size()-counter);
    
}

int main()
{
    vector<int> arr = {};
    display(arr);
    cout<<removeElement(arr,0)<<endl;
    display(arr);
    return 0;
}