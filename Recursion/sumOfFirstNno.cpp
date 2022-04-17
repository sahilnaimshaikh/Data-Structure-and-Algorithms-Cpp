// There are 2 patterns to solve this problem 
//     1) functional way
//     2) parameterized way


// 1) functional way 

    // #include<iostream>
    // using namespace std;

    // int  sum(int n){
    //     if(n<1) return 0;
    //     return n + sum(n-1);
    // }       
    // int main(){
                
    //     int n = 5;
    //     cout<<"Sum of first 5 no. is "<<sum(n);   
                
    // return 0;
    // }


// 2) parameterized way 

    #include<iostream>
    using namespace std;

        void sums(int n , int sum){

            if(n<1){
                cout<<"sum is "<<sum;
                return;
            } 
            sums(n-1, sum+n);

        }        
                
    int main(){
                
            int n = 5;
            sums(n,0);
                
    return 0;
    }