#include <bits/stdc++.h>
using namespace std;

void myau() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int c0 = 0;
    int c1 = 0;
    for (char meow : s) {
        if (meow == '0') {
            c0++;
        } else if (meow == '1') {
            c1++;
        }
    }
    int c2 = k - c0 - c1;

    string salution(n, '?');

    for (int i = 0; i < c0; ++i) {
        salution[i] = '-';
    }
    for (int i = n - 1; i >= n - c1; --i) {
        salution[i] = '-';
    }

    int npp = n - c0 - c1;
    int kpp = c2;

    if (npp > 0 && npp == kpp) {
        for (int i = c0; i <= n - c1 - 1; ++i) {
            salution[i] = '-';
        }
    } else if (npp > kpp) {
        int start_idx = c0 + kpp;
        int end_idx = n - c1 - c2 - 1;
        for (int i = start_idx; i <= end_idx; ++i) {
            salution[i] = '+';
        }
    }

    cout << salution << "\n";
}

int main() {
 //myauuu 
    int t;
    cin >> t;
    while (t--) {
        myau();
    }
    return 0;
}