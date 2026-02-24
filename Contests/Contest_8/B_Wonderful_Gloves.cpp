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
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &l, vll &r, ll &n, ll &k){

    vll rem (n);
    ll tot = 0;

    for(ll i = 0; i < n; i++){

        if(l[i] >= r[i]){

            tot += l[i];
            rem[i] = r[i];
        }
        else{

            tot += r[i];
            rem[i] = l[i];
        }
    }

    sort(rall(rem));

    for(ll i = 0; i < k-1; i++){

        tot += rem[i];
    }

    tot++;  // to make final pair

    cout << tot << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        vll l (n), r (n);

        for(ll i = 0; i < n; i++) cin >> l[i]; 
        for(ll i = 0; i < n; i++) cin >> r[i]; 

        solve(l, r, n, k);
    }
}

