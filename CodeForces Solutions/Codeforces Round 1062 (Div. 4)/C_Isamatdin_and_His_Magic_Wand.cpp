#include <bits/stdc++.h>
using namespace std;

void okhai() {
    int n;
    if (!(cin >> n)) return;
    vector<int> myauu(n);
    bool ood = 0;
    bool evan = 0; //gelian


    for (int i = 0; i < n; i++) {
        if (!(cin >> myauu[i])) return;

        if (myauu[i] % 2 != 0) ood = 1; 
        else evan = 1;
    }

    if (ood && evan) sort(myauu.begin(), myauu.end());


    for (int i = 0; i < n; i++) cout << myauu[i] << (i == n - 1 ? "" : " ");

    
    cout << "\n";
}

int main() {



    int t;



    if (!(cin >> t)) 
    return 0;
    while (t--) 
    okhai();
    return 0;
}
