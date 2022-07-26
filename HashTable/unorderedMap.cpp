#include<bits/stdc++.h>
using namespace std;
               
class unorderedMap{

     static const int bucketArraySize = 20; // 
     list<pair<int, string>> bucketArray[bucketArraySize]; // An array of linkedList 
    
    public:
        bool isEmpty(){
            int sum = 0;
            for(int i = 0; i< bucketArraySize; i++){
                sum += bucketArray[i].size();
            }
            if(sum>0)return false;
            return true;
        };

        int hashFunction(int key);
        void insert(int key, string value);
        void remove(int key);
        string search(int key);
        void printMap();
};       
          
    
   int unorderedMap :: hashFunction(int key){
      return key % bucketArraySize;
    }

    void unorderedMap :: insert(int key, string value){

        int hashIndex = hashFunction(key);
        auto& linkedList = bucketArray[hashIndex];
        auto head = begin(linkedList);
        bool keyAlreadyPresent = false;
        while(head != end(linkedList)){
            if(head->first == key){ // if key is already present in the hashtable then we will update the value
                head-> second = value;
                keyAlreadyPresent = true;
                break;
            }
            head++;
        }
        if(!keyAlreadyPresent) linkedList.emplace_back(key, value); // if key is not present then we will add it;

    }
    
    void unorderedMap :: remove(int key){
        
        int hashIndex = hashFunction(key);
        auto& linkedList = bucketArray[hashIndex];
        auto head = begin(linkedList);
        bool whetherKeyPresent = false;
        while(head != end(linkedList)){
            if(head->first == key){
                linkedList.erase(head);
                whetherKeyPresent = true;
                break;
            }
            head++;
        }
        if(!whetherKeyPresent) cout<<" key not found in the hash table";
    }

    string unorderedMap :: search(int key){
       
            int hashIndex = hashFunction(key);    
            auto linkedList = bucketArray[hashIndex];
            auto head = begin(linkedList);
            bool isfound = false;
            while( head != end(linkedList)){
                if(head->first == key) {
                    return head->second;
                    isfound = true;
                    break;
                }
                head++;
            }
            if(isfound){}
            return "Key not found ";
        

    }

    void unorderedMap :: printMap(){
        for (int i = 0; i < bucketArraySize; i++)
        {
            if(bucketArray[i].size() == 0) continue;
            auto linkedList = bucketArray[i];
            auto head = begin(linkedList);
            while( head != end(linkedList)){
                cout<<" key: "<<head->first<<" "<<" value: "<<head->second<<endl;
                head++;
            }
        }
    }


int main(){

     unorderedMap contact;
    //  cout<<contact.isEmpty();     
     contact.insert(789, "Naim");
     contact.insert(789, "alina");
     contact.insert(456, "Sahil");
     contact.remove(789);
     cout<<contact.search(4556);
    // contact.printMap();
          
return 0;
}