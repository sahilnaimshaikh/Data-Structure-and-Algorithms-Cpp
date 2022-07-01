#include <bits/stdc++.h>
using namespace std;

    bool comp(vector<int> a,vector<int> b){
        if(a[1]<b[1])return false;
        else return true;
    }

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), comp);
    int maxi = 0;
    for (int i = 0; i < boxTypes.size(); i++)
    {
        if(boxTypes[i][0]<=truckSize){
            maxi = maxi + boxTypes[i][1]*boxTypes[i][0];
            truckSize-=boxTypes[i][0];
        }
        else{
            maxi = maxi + truckSize*boxTypes[i][1];
            truckSize = 0;
        }
        if(truckSize == 0) break;
    }
    return maxi;
}

int main()
{
    vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
    int truckSize = 4;
    maximumUnits(boxTypes, truckSize);
    return 0;
}