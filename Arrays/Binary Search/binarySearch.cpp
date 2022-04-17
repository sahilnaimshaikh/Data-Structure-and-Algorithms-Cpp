#include<bits/stdc++.h>
using namespace std;
            
        int binarySearch(int arr[], int size, int elementToSearch){
            int low,mid,high;
            low = 0,high = size-1;
            while(low<=high){
                mid = (low+high)/2;
                if (arr[mid] == elementToSearch)
                {
                    return mid;
                }
                if (arr[mid] < elementToSearch)
                {   
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
              
            }
                return -1;
        }
int main(){
            
        int arr[] = {1,22,33,45,56,62,75,92,111,199};
        int size = sizeof(arr)/sizeof(int);
        int elementToSearch = 78;
        cout<<"Element "<<elementToSearch<<" is found at index "<<binarySearch(arr, size, elementToSearch);

return 0;
}