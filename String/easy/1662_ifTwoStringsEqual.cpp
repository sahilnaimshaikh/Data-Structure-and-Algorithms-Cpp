#include<bits/stdc++.h>
using namespace std;

 bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string fromWord1 ;
        string fromWord2;
        for(auto it : word1)fromWord1 += it;
        
        for(auto it : word2)fromWord2 += it;
        
        if(fromWord1 == fromWord2)return true;
        return false;
    }           
            
int main(){
      vector<string> word1 = {"sahilsh", "aikh"};
      vector<string> word2 = {"sah", "ilshaikh"};

        cout<<arrayStringsAreEqual(word1, word2);
            
return 0;
}