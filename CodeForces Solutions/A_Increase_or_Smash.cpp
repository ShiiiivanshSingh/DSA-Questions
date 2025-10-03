#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        set<int> uq;


        for (int g = 0; g < n; g++) {
            int vass;
            cin >> vass;
            uq.insert(vass);
        }
        
        int count = uq.size();
        int myau = 2* count - 1;
        
        cout << myau << endl;
    }
    
    return 0;
}
