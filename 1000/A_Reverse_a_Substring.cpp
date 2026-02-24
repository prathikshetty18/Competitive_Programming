#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(string &s, ll &n){

    for(int i = 1; i < n; i++){

        if(s[i] < s[i-1]){

            cout << "YES\n";
            cout << i-1+1 << sp << i+1 << nl;
            return;
        }
    }

    cout << "NO\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;

    while(t > 0){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}

