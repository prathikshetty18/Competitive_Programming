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

class DisjointSet{

    public:

    vll parent, size;

    DisjointSet(int n){

        parent.resize(n);
        size.resize(n, 1);

        for(ll i = 0; i < n; i++){

            parent[i] = i;
        }
    }

    ll findUParent(ll node){

        if(node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(ll u, ll v){

        ll up_u = findUParent(u);
        ll up_v = findUParent(v);

        if(up_u == up_v) return;

        if(size[up_u] <= size[up_v]){

            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else{

            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

void solve(ll &n, ll &m){

    DisjointSet ds(n+1);

    for(ll i = 0; i < m; i++){
    
        ll k; cin >> k;

        ll prev; 
        
        if(k > 0) cin >> prev;

        for(ll i = 1; i < k; i++){
        
            ll u; cin >> u;

            if(ds.findUParent(u) != ds.findUParent(prev)){

                ds.UnionBySize(u, prev);
            }

            prev = u;
        }
    }

    for(ll i = 1; i <= n; i++){
    
        cout << ds.size[ds.findUParent(i)] << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        solve(n, m);
    }
}

