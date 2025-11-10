#include <iostream>
using namespace std;

void solve() {
    int a; int b; int c; int d;
    if (!(cin >> a >> b >> c >> d)) return;
    if (a == b && b == c && c == d)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}
