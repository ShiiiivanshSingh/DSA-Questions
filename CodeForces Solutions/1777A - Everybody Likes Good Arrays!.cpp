#include <bits/stdc++.h>
using namespace std;
 
 
 
int main(){
    int t; cin>> t;
    while(t--){
        int n ; cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n;i++) cin>>arr[i];
        
        int diff = 0, sum = 1;
        for(int i = 1; i < n; i++){
            if(arr[i]%2 == arr[i-1]%2) sum++;
            else {
                diff += sum-1;
                sum = 1;
            }
        }
        diff += sum-1;
        cout << diff << "\n";
    }
}




    

