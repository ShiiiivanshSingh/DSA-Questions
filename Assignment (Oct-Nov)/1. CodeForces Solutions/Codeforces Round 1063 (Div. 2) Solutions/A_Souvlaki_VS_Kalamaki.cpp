#include <bits/stdc++.h>
using namespace std;

void myau(){



        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto& x : arr) {
            cin >> x;
        }
        sort(arr.begin(), arr.end());
        bool ok = true;
        for (int j = 1; j < n - 1; j += 2) {
            if (arr[j] != arr[j + 1]) {
                ok = false;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    
    
}
int main() {

    int t;
    cin >> t;
  while(t--) myau();
    return 0;
}