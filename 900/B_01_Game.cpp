#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s){

    int n = s.size();

    int zeros = 0;
    int ones = 0;

    for(int i = 0; i < n; i++){

        zeros += s[i] == '0';
        ones += s[i] == '1';
    }

    int removals = min(zeros, ones);

    if(removals & 1) cout << "DA\n";
    else cout << "NET\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        string s;
        
        cin >> s;

        solve(s);

        t--;
    }
}

