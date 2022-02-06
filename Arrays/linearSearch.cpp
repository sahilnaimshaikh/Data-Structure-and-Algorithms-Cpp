#include<bits/stdc++.h>
using namespace std;

        int linearSearch(int arr[],int size,int elementToSearch) {

            for (int i = 0; i < size; i++)
            {
                if (arr[i] == elementToSearch)
                {
                    return i;
                }
                
            }
            return -1;
        }
            
int main(){
            
        int arr[] = {12,34,86,34,78,658,5,6,99};
        int size = sizeof(arr)/sizeof(int);
        int elementToSearch = 99;
        cout<<"Element "<<elementToSearch<<" is found at index "<<linearSearch(arr, size, elementToSearch);

return 0;
}