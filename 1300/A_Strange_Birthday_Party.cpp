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

void solve(vll &v, vll &a, ll &n, ll &m){

    sort(rall(v));

    ll l = 0, r = 0, tot = 0;

    while(l < n){

        ll k = v[l];

        if(r < m && a[r] < a[k-1]){

            tot += a[r];
            r++;
        }
        else tot += a[k-1];

        l++;
    }

    cout << tot << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vll v (n), a (m);

        for(ll i = 0; i < n; i++) cin >> v[i]; 
        for(ll i = 0; i < m; i++) cin >> a[i]; 

        solve(v, a, n, m);
    }
}

