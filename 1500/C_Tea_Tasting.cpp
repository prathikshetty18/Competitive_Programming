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
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &a, vll &b, ll &n){

    vll preb (n+1);
    preb[0] = 0;

    for(ll i = 1; i <= n; i++){
    
        preb[i] += (preb[i-1] + b[i-1]);
    }

    // debug(preb);

    vll addItself (n, 0), addExtra (n, 0);

    for(ll i = 0; i < n; i++){

        ll totTea = a[i] + preb[i];
    
        ll ind = lower_bound(preb.begin() + i + 1, preb.end(), totTea) - preb.begin();

        addItself[i] += 1;

        if(ind - 1 < n){

            addItself[ind-1] -= 1;

            addExtra[ind-1] += totTea - preb[ind-1];
        }

        // cout << ind << nl;
    }

    vll ans (n, 0);

    ans[0] = addItself[0] * b[0] + addExtra[0];

    for(ll i = 1; i < n; i++){
    
        addItself[i] += addItself[i-1];
        ans[i] = addItself[i] * b[i] + addExtra[i];
    }

    print(ans);

    // debug(addItself);
    // debug(addExtra);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll a (n), b (n);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n);
    }
}

