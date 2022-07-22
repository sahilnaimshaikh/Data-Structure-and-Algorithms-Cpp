#include<bits/stdc++.h>
using namespace std;
 class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m,vector<int>(n)), fail;
        if(m*n != original.size()) return fail; // if the dimensions are not matching with the size of original then return null/
        int index = 0;
        for (int i = 0; i < m; i++)
        {   
            for (int j = 0; j < n; j++)
            {   
                result[i][j] = original[index];
                index++;
            }
           
        }
        return result;
    }
};           
            
int main(){

vector<int> original = {1,2,3,4,5,6};
int m = 2, n = 3       ;  
Solution sol;
for(auto it:sol.construct2DArray(original, m , n)){
    for(auto i: it)cout<<i<<" ";
    cout<<endl;
}
            
return 0;
}