#include <bits/stdc++.h>
using namespace std;


// hmu here -> https://linktr.ee/ShivanshPratapSingh
// ni haoo

long long gcd(long long a, long long b) {
    while (b) { //maine ise ek test me glt kr diya tha i want to kmms for that lol
        a %= b; 
        //im bored oota my mind
        swap(a, b); // hmu discprd or teiiter if u stalking me 
    } // folow me on spotify myau i have cool playlists there
    return a; // what are u doing hree man come on
    // herroic won today 2-0 vs aurora myauuuu
}

void okreprot() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> akkk(n);


    for (int i = 0; i < n; i++) if (!(cin >> akkk[i])) return;
    const int idk = 60;


    for (int ikka = 2; ikka <= idk; ikka++) {
        bool found = 0;
        for (long long val : akkk) {
            if (gcd(val, ikka) == 1) {
                found = 1;
                break;
            }
        }
        if ( found  ) {
            cout << ikka << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) okreprot();
    return 0;
}

