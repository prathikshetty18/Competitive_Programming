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

void solve(vll &v, string &s, ll &n){

    ll x0 = 0, x1 = 0;
    vll preXor (n+1, 0);
    
    for(ll i = 0; i < n; i++){
        
        if(s[i] == '0') x0 ^= v[i];
        else x1 ^= v[i];

        preXor[i+1] = preXor[i] ^ v[i];
    }

    ll q; cin >> q;

    for(ll i = 0; i < q; i++){

        // cout << "x0: " << x0 << sp << "x1: " << x1 << nl;
    
        ll type; cin >> type;

        if(type == 1){

            ll l, r; cin >> l >> r;

            x0 = x0 ^ (preXor[r] ^ preXor[l-1]);
            x1 = x1 ^ (preXor[r] ^ preXor[l-1]);
        }
        else{

            ll sym; cin >> sym;

            if(sym == 0){

                cout << x0 << sp;
            }
            else{

                cout << x1 << sp;
            }
        }
    }

    cout << nl;

    // cout << "x0: " << x0 << sp << "x1: " << x1 << nl;
    // print(preXor);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        string s; cin >> s;

        solve(v, s, n);
    }
}

