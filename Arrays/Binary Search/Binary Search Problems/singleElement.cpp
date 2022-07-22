#include<bits/stdc++.h>
using namespace std;

int singleElement(int A[], int size){
    if(size==1)return A[0];
    int low = 0;
    int high = size-1;
    int mid;
    while(low<=high){
        mid = (high + low)/2;
        // 1st Approach

        // if(mid%2==0){
        //     if(A[mid]==A[mid+1]){
        //         low = mid+1;
        //     }
        //     else{
        //         high = mid-1;
        //     }
        // }
        // else{
        //     if(A[mid]==A[mid-1]){
        //         low = mid+1;
        //     }
        //     else{
        //         high = mid-1;
        //     }
        // }

        // 2nd Approach
        if(A[mid]==A[mid^1]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }
    return A[low];
}          
            
int main(){
            
        int A[]={11,11,12,12,13,13,14,14,19,19,22,22,33};
        int size = sizeof(A)/sizeof(int);
        cout<<"Single Element in the Array is : "<<singleElement(A,size);
            
return 0;
}