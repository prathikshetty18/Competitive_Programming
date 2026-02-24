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

void dfs(ll node, ll parent, vvll &adj, map<ll, map<ll, ll>> &index, vll &dp, ll &maxi){

    for(auto adjNode : adj[node]){

        if(adjNode != parent){

            if(index[node][parent] < index[node][adjNode]){

                dp[adjNode] = dp[node];
            }
            else dp[adjNode] = dp[node] + 1;

            maxi = max(maxi, dp[adjNode]);

            dfs(adjNode, node, adj, index, dp, maxi);
        }
    }
}

void solve(vvll &adj, map<ll, map<ll, ll>> &index, ll &n){

    vll dp (n, 0);
    dp[0] = 1;

    ll maxi = LLONG_MIN;

    dfs(0, -1, adj, index, dp, maxi);

    // print(dp);

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        map<ll, map<ll, ll>> index;

        vvll adj (n);

        for(ll i = 0; i < n-1; i++){
            
            ll u, v; cin >> u >> v;
            u--;
            v--;

            adj[u].pb(v);
            adj[v].pb(u);
            index[u][v] = i+1;
            index[v][u] = i+1;
        }

        solve(adj, index, n);
    }
}

