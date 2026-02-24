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

void solve(vvll &adj, vll &c, vll &par, ll &n){

    vll nodes;

    // print(c);
    // print(par);

    for(ll i = 0; i < n; i++){
        
        ll val = c[i];
        
        // cout << "node: " << i+1 << nl;

        for(auto child : adj[i]){

            if(child != par[i]){

                // cout << "child: " << child+1 << sp;

                val &= c[child];
            }
        }

        // cout << nl;

        if(val == 1) nodes.pb(i+1);
    }

    if(nodes.size()){

        print(nodes);
    }
    else{

        cout << -1 << nl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vvll adj (n);
        vll c (n), par (n, -1);

        for(ll i = 0; i < n; i++){

            ll pi, ci; cin >> pi >> ci;

            c[i] = ci;

            if(pi == -1) continue;

            pi--;
            adj[i].pb(pi);
            adj[pi].pb(i);

            par[i] = pi;
        }

        solve(adj, c, par, n);
    }
}

