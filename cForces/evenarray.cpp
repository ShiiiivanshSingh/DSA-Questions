#include <iostream>
#include <vector>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        int evil1 = 0 , ovil1 = 0;
        for(int i = 0; i< n; i++){
            if(i % 2 != a[i] % 2){
                if( i%2 == 0) evil1++;
                else ovil1++;
            }
        }
      if(evil1 == ovil1)  cout << evil1 << endl;
      else cout << -1 << endl; 
    }
        return 0;
}