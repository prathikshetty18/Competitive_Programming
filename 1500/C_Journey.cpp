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
#define vld vector<ld>
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
 
void dfs(vvll &adj, ll node, ll parent, vll &dist, vld &prob){
 
    if(parent != -1) dist[node] = dist[parent] + 1;
    if(parent == 0) prob[node] = prob[parent] * (1 / (long double) adj[parent].sz());
    else if(parent != -1) prob[node] = prob[parent] * (1 / (long double) (adj[parent].sz() - 1));
 
    for(auto adjNode : adj[node]){
 
        if(adjNode != parent){
 
            dfs(adj, adjNode, node, dist, prob);
        }
    }
}
 
void solve(vvll &adj, ll &n){
 
    if(n == 1){
 
        cout << 0 << nl;
        return;
    }
 
    vll dist (n, 0);
    vld prob (n, 0);
    prob[0] = 1; 
 
    dfs(adj, 0, -1, dist, prob);
 
    // debug(dist, splitNodes);
 
    ld ans = 0;
 
    for(ll i = 1; i < n; i++){
    
        if(adj[i].sz() == 1){
 
            // debug(dist[i], splitNodes[i]);
 
            ans += dist[i] * prob[i];
        }
    }
 
    // debug(ans);
 
    cout << fixed << setprecision(6) << ans;
}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t = 1;
 
    while(t--){
 
        ll n;
        
        cin >> n;
 
        vvll adj (n);
 
        for(ll i = 0; i < n - 1; i++){
            
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
 
        solve(adj, n);
    }
}