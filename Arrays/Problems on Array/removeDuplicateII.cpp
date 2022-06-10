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
    int checker = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if(element != nums[j]){
           element = nums[j];
           nums[counter] = element;
           counter++;
           checker=1;
        }
        else{
            checker++;
            if(checker==2){
                nums[counter] = nums[j];
                counter++;
            }
        }
    }
    return counter;
    
}
int main()
{

    vector<int> arr = {0,0,1,1,1,1,2,3,3};
    display(arr);
    removeDuplicates(arr);
    display(arr);
    return 0;
}