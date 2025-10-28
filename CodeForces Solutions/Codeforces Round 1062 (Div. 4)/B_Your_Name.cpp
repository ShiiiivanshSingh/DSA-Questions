#include <bits/stdc++.h>
using namespace std;

void nyauu() {
    int n;
    if (!(cin >> n)) return;
    string s; string t;
    if (!(cin >> s >> t)) return;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {

    int q;
    if (!(cin >> q)) return 0;
    while (q--) nyauu();
    return 0;
}
