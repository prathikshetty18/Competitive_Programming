#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n){

    map<ll, ll> mp;

    mp[0] = 3;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 1;
    mp[5] = 1;
    
    for(ll i = 0; i < n; i++){

        if(mp.find(v[i]) != mp.end()){

            mp[v[i]]--;

            if(mp[v[i]] == 0){

                mp.erase(v[i]);
            }

            if(mp.size() == 0){

                cout << i + 1 << nl;
                return;
            }
        }
    }


    if(mp.size() == 0){

        cout << n << nl;
        return;
    }

    cout << 0 << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

