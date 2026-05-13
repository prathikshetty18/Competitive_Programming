#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
#define ld long double
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }


ll dfs(ll node, ll parent, vvll &adj, vll &depth, vll &subtree, vll &happinessAddition){

    if(parent != -1) depth[node] = 1 + depth[parent];
    ll currNodes = 1;

    for(auto adjNode : adj[node]){

        if(adjNode != parent){

            currNodes += dfs(adjNode, node, adj, depth, subtree, happinessAddition);
        }
    }

    subtree[node] = currNodes;
    happinessAddition[node] = subtree[node] - depth[node];
    return subtree[node];
}

void solve(vvll &adj, ll &n, ll&k){

    vll depth (n, 0);
    vll subtree (n, 0);
    vll happinessAddition (n, 0);

    depth[0] = 1;
    dfs(0, -1, adj, depth, subtree, happinessAddition);

    sort(rall(happinessAddition));

    // debug(depth, subtree, happinessAddition);

    ll ans = 0;

    for(ll i = 0; i < n - k; i++) ans += happinessAddition[i];
    cout << ans << nl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        vvll adj (n);

        for(ll i = 0; i < n-1; i++){
            
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        solve(adj, n, k);
    }
}

