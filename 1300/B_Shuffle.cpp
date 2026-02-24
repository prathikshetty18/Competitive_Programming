#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"
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

void solve(vpll &v, ll &n, ll &x, ll &m){

    ll l = x, r = x;

    for(auto [li, ri] : v){

        if((li <= l && l <= ri) || (li <= r && r <= ri)){

            l = min(l, li);
            r = max(r, ri);
        }
    }

    cout << r - l + 1 << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, x, m;
        
        cin >> n >> x >> m;

        vpll v (m);

        for(ll i = 0; i < m; i++) cin >> v[i].ff >> v[i].ss; 

        solve(v, n, x, m);
    }
}

