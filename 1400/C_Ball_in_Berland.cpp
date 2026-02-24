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
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &boy, vll &girl, ll &a, ll &b, ll &n){

    vvll adj (a + b + 2);
    ll tot = 0;

    for(ll i = 0; i < n; i++){
    
        adj[boy[i]].pb(girl[i] + a);
        adj[girl[i] + a].pb(boy[i]);
    }

    for(ll i = 0; i < n; i++){
    
        ll edg1 = adj[boy[i]].size();
        ll edg2 = adj[girl[i] + a].size();
        
        tot += n - edg1 - edg2 + 1; 
    }

    cout << tot/2 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll a, b, n;
        
        cin >> a >> b >> n;

        vll boy (n), girl (n);

        for(ll i = 0; i < n; i++) cin >> boy[i]; 
        for(ll i = 0; i < n; i++) cin >> girl[i]; 

        solve(boy, girl, a, b, n);
    }
}

