#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(string &s, ll &n){

    unordered_map<char, ll> mp; // char -> count

    ll count = 0;

    for(ll i = 0; i < n; i++){

        mp[s[i]]++;

        count += mp.size();
    }

    cout << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        string s;

        cin >> s;

        solve(s, n);

        t--;
    }
}

