#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //   vector<int> addToArrayForm(vector<int>& num, int k) {
    //     int sum = 0;
    //     vector<int> result;
    //    for (int i = 0; i < num.size(); i++)
    //    {
    //      sum = (sum*10) + num[i];
    //    }
    //    sum+=k;
    //     while(sum!=0){
    //         int r = sum%10;
    //         result.push_back(r);
    //         sum/=10;
    //     }
    //    reverse(result.begin(), result.end());
    //     return result;
    // }   
    vector<int> addToArrayForm(vector<int> A, int K) {
 for(int i=A.size()-1;i>=0&&K>0;i--)
 {
     A[i]+=K;
     K=A[i]/10;
     A[i]%=10;
 }
     while(K>0)
     {
         A.insert(A.begin(),K%10);
         K/=10;
     }
     return A;
    }   
};
          
int main(){

  vector<int> num = {9,9,9,9,9,9};
  int k = 1;
  Solution sol;
  for(auto it : sol.addToArrayForm(num, k)) cout<<it<<" ";
    
          
          
return 0;
}