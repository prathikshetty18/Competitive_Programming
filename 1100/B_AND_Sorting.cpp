#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n){

    ll x = -1;

    for(ll i = 0; i < n; i++){

        if(v[i] != i){

            // cout << "v[i]: " << v[i] << " v[v[i]]: " << v[v[i]] << " val: " << (v[i] & v[v[i]]) << nl;


            
            if(x == -1) x = v[i];
            else x = x & v[i];

            // swap(v[i], v[v[i]]);
        }
    }

    cout << x << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

