#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "

void solve(vector<ll> &v, ll &n){

    if(n == 1 || n == 0){

        cout << -1 << endl;
        return;
    }

    unordered_map<ll, vector<ll>> mp;

    mp[v[0]].push_back(1);

    for(ll i = 1; i < n; i++){

        if(v[i] != v[i-1] && mp[v[i-1]].size() == 1){

            cout << -1 << endl;
            return;
        }

        mp[v[i]].push_back(i+1);
        continue;
    }

    if(mp[v[n-1]].size() == 1){

        cout << -1 << endl;
        return;
    }

    ll prev = -1;

    for(ll j = 0; j < n; j++){

        if(v[j] != prev){

            int curr = mp[v[j]][0];

            for(ll i = 1; i < mp[v[j]].size(); i++){

                cout << mp[v[j]][i] << sp;
            }

            cout << curr << sp;

            prev = v[j];
        }
    }

    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

