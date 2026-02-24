#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
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
ll mod_sub(ll a, ll b, ll m = mod) { return ((a % m - b % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

class DisjointSet {

    public:

    vll size;
    vll parent;

    DisjointSet(ll n){

        size.resize(n+1, 1);
        parent.resize(n+1);

        for(ll i = 0; i <= n; i++){
        
            parent[i] = i;
        }
    }

ll findUParent(ll node){

        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(ll node1, ll node2){

        ll up_node1 = findUParent(node1);
        ll up_node2 = findUParent(node2);

        if(up_node1 == up_node2) return;

        if(size[up_node1] <= size[up_node2]){

            parent[up_node1] = up_node2;
            size[up_node2] += size[up_node1];
        }
        else{

            parent[up_node2] = up_node1;
            size[up_node1] += size[up_node2];
        }
    }
};

ll findPowerBinExpo(ll a, ll b){

    ll ans = 1;

    while(b){

        if(b & 1){
            
            ans = mod_mul(ans, a);
        }
        
        a = mod_mul(a, a);
        b >>= 1;
    }

    return ans;
}

void solve(ll &n, ll &k){

    DisjointSet ds(n);

    for(ll i = 0; i < n-1; i++){
    
        ll node1, node2, col;

        cin >> node1 >> node2 >> col;

        if(col == 0){

            ds.UnionBySize(node1, node2);
        }
    }

    ll total = findPowerBinExpo(n, k);

    ll good = 0;

    for(ll i = 1; i <= n; i++){

        if(ds.findUParent(i) == i){

            good = mod_add(good, findPowerBinExpo(ds.size[i], k));
        }
    }

    cout << mod_sub(total, good) << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        solve(n, k);
    }
}