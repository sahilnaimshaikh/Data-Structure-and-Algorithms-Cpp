#include<bits/stdc++.h>
using namespace std;
               
  vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
      int n = intervals.size();
      vector<vector<int>> mergedIntervals;
      if(intervals.size() == 0) return mergedIntervals;
      sort(intervals.begin(), intervals.end());
      vector<int> temporaryInterval = intervals[0];

      for(int i = 0; i< n ; i++){
          if(intervals[i][0] <= temporaryInterval[1]){
              temporaryInterval[1] = max(intervals[i][1], temporaryInterval[1]);
          }
          else{
              mergedIntervals.emplace_back(temporaryInterval);
              temporaryInterval = intervals[i];
          }
      }
      mergedIntervals.emplace_back(temporaryInterval);
      return mergedIntervals;

  }        
          
int main(){
          
        //   vector<vector<int>> intervals = {{1,4}, {1,3},{2,6},{8,10},{15,18}};
          vector<vector<int>> intervals ;
          for(auto it : mergeIntervals(intervals)){
              for(auto i: it){
                  cout<<i<<" ";
              }
              cout<<endl;
          }
          
return 0;
}