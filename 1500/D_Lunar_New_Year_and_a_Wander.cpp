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


void dfs(ll currNode, vvll &adj, vll &vis, vll &res, priority_queue<ll, vll, greater<ll>> &availableNodes){

    res.pb(currNode+1);
    vis[currNode] = 1;
    availableNodes.pop();

    for(auto adjNode : adj[currNode]){

        if(!vis[adjNode]){

            availableNodes.push(adjNode);
        }
    }

    while(!availableNodes.empty()){

        ll nextNode = availableNodes.top();

        if(!vis[nextNode]){

            dfs(nextNode, adj, vis, res, availableNodes);
        }
        else availableNodes.pop();
    }
}

void solve(vvll &adj, ll &n, ll &m){

    vll vis (n, 0);
    vll res;
    priority_queue<ll, vll, greater<ll>> availableNodes;
    availableNodes.push(0);

    dfs(0LL, adj, vis, res, availableNodes);

    print(res);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vvll adj (n);

        for(ll i = 0; i < m; i++){
            
            ll n1, n2;
            cin >> n1 >> n2;
            adj[--n1].pb(--n2);
            adj[n2].pb(n1);
        }

        solve(adj, n, m);
    }
}

