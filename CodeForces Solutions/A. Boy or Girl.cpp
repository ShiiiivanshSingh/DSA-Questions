    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
        string s;
        cin >> s;
        
        set<char> a(s.begin(), s.end());
        
        if (a.size() % 2 == 0)  cout << "CHAT WITH HER!";
        else    cout << "IGNORE HIM!";
        return 0;
    }
