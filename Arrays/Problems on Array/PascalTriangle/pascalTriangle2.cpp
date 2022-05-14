#include<bits/stdc++.h>
using namespace std;

 vector<int> generate(int numRows) {
        int rows = numRows+1;
        vector<vector<int>> r(rows);

        for (int i = 0; i < rows; i++)
        {
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
            
        }
        return r[numRows];


    }               
          
          
int main(){
          
int numRows;
cout<<"Enter the no. of Rows to be generated";
cin>>numRows;
for(auto it : generate(numRows)){
    
cout<<it<<" ";
    
}         

          
return 0;
}