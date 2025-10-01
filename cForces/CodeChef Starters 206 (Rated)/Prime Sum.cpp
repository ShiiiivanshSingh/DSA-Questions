
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        
        int count_one=0, count_two =0, count_three=0;
        
        for(int i=0;i<n;i++){
            int x;
            cin >> x;

            if(x==1)    count_one++;

            else if(x==2)   count_two ++;

            else     count_three++; //other than 1 n 2
        }
        
        long long final = 0;

        final += 1LL*count_one*(count_one-1)/2; 

    //I-]
        final += 1LL*count_one*count_two ;      
        
        
        final += 1LL*count_two *count_three;        
        
        cout << final << endl;
    }
    return 0;
}
