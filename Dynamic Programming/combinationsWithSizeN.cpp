//In this program we have been given a string and we had to find the all possible lexicographical combinations of any given combination Length.

#include<bits/stdc++.h>
using namespace std;
               
 void combination(int i ,string ch, int cl,string ans, vector<string>& comb){

        if(cl == 0 ){
            comb.push_back(ans);
            return;
        }
        if(i == ch.size())return;

        //pick 
        ans.push_back(ch[i]);
       combination(i+1, ch, cl-1, ans, comb);

        //not pick 
       ans.pop_back();
       combination(i+1,ch, cl,ans,comb);

 }       
          
int main(){
          
    string ch = "abcd";
    int cl = 3;
    string ans;
    vector<string> comb;
    combination(0,ch,cl,ans,comb);
    for(auto it : comb) cout<<it<<" ";
          
return 0;
}