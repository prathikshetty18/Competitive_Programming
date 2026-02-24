#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(string &s, ll &n){

    unordered_set<char> set;

    for(ll i = 0; i < n; i++){

        set.insert(s[i]);
    }

    ll u = set.size();      // unique chars 

    // idea => if len between repeating chars is not exactly u + 1 => invalid

    unordered_map<char, ll> mp;

    for(ll i = 0; i < n; i++){

        if(mp.find(s[i]) != mp.end()){

            ll prev = mp[s[i]];

            if(i - prev + 1 != u + 1){

                cout << "NO\n";
                return;
            }
        }

        mp[s[i]] = i;
    }

    cout << "YES\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n;

        string s;

        cin >> s;

        n = s.size();

        solve(s, n);
    }
}

