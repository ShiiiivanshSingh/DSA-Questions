#include <bits/stdc++.h>
using namespace std;

int main() {



    int t; 
    cin >> t;
    while (t--) {


        int n; 
        cin >> n;
        vector<long long> myau(n);

        for (auto &i : myau) cin >> i;

        bool achaahaaaa = false;
        for (int i = 0; i < n && !achaahaaaa; i++) {

            for (int j = i + 1; j < n && !achaahaaaa; j++) {
                
                if ((myau[j] % myau[i]) % 2 == 0) {
                    cout << myau[i] << " " << myau[j] << "\n";
                    achaahaaaa = true;
                }
            }
        }
        if (!achaahaaaa) cout << -1 << "\n";
    }
}
