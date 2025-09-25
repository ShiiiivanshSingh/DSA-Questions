#include <bits/stdc++.h>
using namespace std;
int main(){


    int testcase;
    cin>>testcase;

    while(testcase--){

        int n;cin>>n;
        int x;
        int negative_count =0; 
        int zero_count=0;

        for(int i=0;i<n;i++){
            cin>>x;if(x==0) zero_count++;
            if(x==-1)   negative_count ++;
        }
        
        int myau = zero_count + (negative_count %2)*2;
        
        cout<<myau<<"\n";
    }
}
