#include<iostream>
using namespace std;


        void insert(int arrae[], int index, int &size, int element, int capacity){

            if (size >= capacity || index > size-1)
            {
                cout<<"An error has occured while insertion."<<endl;
            }
            else{
                for (int i = size ; i >= index ; i--)
                {
                    arrae[i+1] = arrae[i]; 
                }
                arrae[index] = element;
                size+=1;
            }   
        }

        void display(int arrae[], int size){
                for (int i = 0; i < size; i++)
                {
                    cout<<arrae[i]<<"\t";
                }
                cout<<endl;   
        }  
            
int main(){
            
        int arrae[100] = {1,23,4,45,2,75,4};
        int size = 7, element = 9, capacity = 100, index = 7;
        display(arrae, size);
        cout<<size<<endl;
        insert(arrae, index, size,element,capacity);
        display(arrae, size);
        cout<<size<<endl;
        
return 0;
}
// couldnt get the right solution for the testcases. All testCases failed except the first one