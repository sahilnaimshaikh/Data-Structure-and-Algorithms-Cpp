#include<bits/stdc++.h>
using namespace std;

 static bool comp(vector<int> a, vector<int> b){
        if(a[0] > b[0])return false;
        else if(a[0] < b[0])return true;
        else {
            if(a[1] > b[1])return false;
            else return true;
        }
    }
    bool checkStraightLine(vector<vector<int>>& c) {
        
        sort(c.begin(), c.end(), comp);// for sorting the coordinates
        
        // for(auto it : c){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        
        float distance = sqrt(pow((c[0][0]-c[c.size()-1][0]),2)+pow((c[0][1]-c[c.size()-1][1]),2));
        // float distance = sqrt(pow((1-6),2)+pow((2-7),2));
        float totalDistance = 0;
        for(int i = 1; i < c.size(); i++){
          totalDistance += sqrt(pow((c[i][0]-c[i-1][0]),2)+pow((c[i][1]-c[i-1][1]),2));
        }
        cout<<distance<<" "<<totalDistance;
        if(int(distance) == int(totalDistance)){
         cout<<"inside if";
            return true;
        }
        return false;
    }      
            
int main(){
        
    vector<vector<int>> c = {{0,1},{-6,-17},{3,10},{-7,-20},{1,4},{4,13},{9,28},{7,22}};
    cout<<checkStraightLine(c);
        
            
return 0;
}