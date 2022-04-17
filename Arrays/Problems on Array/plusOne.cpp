#include<bits/stdc++.h>
#include <math.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        vector<int> resultVector;
        
        string resultStr;
        long long int result = 0;

        for (int i = 0; i < digits.size(); i++)
        {
           result = result + (digits[i]*pow(10,(digits.size()-(i+1))));
        }
        result++;
       long long int  n = result;
       while(n>0){
           int r = n%10;
           resultVector.emplace_back(r);
           n/=10;
       }
    
       for (int i = 0; i < resultVector.size()/2 ; i++)
       {
           int temp = resultVector[resultVector.size()-i-1];
           resultVector[resultVector.size()-i-1] = resultVector[i];
           resultVector[i] = temp;
       }
       return resultVector;

}          
            
int main(){
            
        vector<int> arr = {1,2,3,4};
        plusOne(arr);
            
return 0;
}

//submission fail on leetcode ... some testCases didnt pass