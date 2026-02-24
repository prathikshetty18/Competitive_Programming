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

void dfs(ll node, vvll &adj, vll &vis, ll &white, ll &black, ll col){

    white += col == 0;
    black += col == 1;

    vis[node] = 1;

    for(auto adjNode : adj[node]){

        if(vis[adjNode] == 0){

            dfs(adjNode, adj, vis, white, black, !col);
        }
    }
}

void solve(vvll &adj, ll &n){

    ll white = 0, black = 0;

    vll vis (n+1, 0);

    dfs(1, adj, vis, white, black, 0);;

    cout << white*black - (n - 1) << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vvll adj (n+1);

        for(ll i = 0; i < n-1; i++){
            
            ll u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        solve(adj, n);
    }
}

