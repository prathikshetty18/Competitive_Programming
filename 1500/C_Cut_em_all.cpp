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

ll ans = 0;

ll DFS(ll node, vvll &adj, ll parentNode){

    ll subtreeNodes = 1;

    for(auto adjNode : adj[node]){

        if(adjNode != parentNode){

            subtreeNodes += DFS(adjNode, adj, node);
        }
    }

    if((subtreeNodes & 1) == 0) ans++;

    // debug(node, subtreeNodes);

    return subtreeNodes;
}

void solve(vvll &adj, ll &n){

    // debug(adj);

    if(n & 1 == 1){

        cout << -1 << nl;
        return;
    }

    DFS(0, adj, -1);

    cout << ans - 1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vvll v (n);

        for(ll i = 0; i < n - 1; i++){

            ll n1, n2;
            cin >> n1 >> n2;
            n1--;
            n2--;

            v[n1].pb(n2);
            v[n2].pb(n1);
        }

        solve(v, n);
    }
}

