#include<bits/stdc++.h>
using namespace std;

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

    horizontalCuts.push_back(h);
    sort(horizontalCuts.begin(), horizontalCuts.end());
    int maxh = horizontalCuts[0];
    for (int i = 1; i < horizontalCuts.size(); i++)
    {
        maxh = max(maxh, horizontalCuts[i]-horizontalCuts[i-1]);
    }
    
    verticalCuts.push_back(w);
    sort(verticalCuts.begin(),verticalCuts.end());
    int maxv = verticalCuts[0];
    for (int i = 1; i < verticalCuts.size(); i++)
    {
        maxv = max(maxv, verticalCuts[i]-verticalCuts[i-1]);
    }
    
    return 1LL*maxv*maxh;
        
    }           
            
int main(){

int h = 5, w = 4;
vector<int> horizontalCuts = {1,3};
vector<int> verticalCuts = {1,2,4};
cout<<maxArea(h,w,horizontalCuts, verticalCuts);   
        
            
return 0;
}