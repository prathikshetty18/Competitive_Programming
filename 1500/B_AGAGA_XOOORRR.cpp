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

void solve(vll &v, ll &n){

    vll preXor (n+1, 0);

    for(ll i = 0; i < n; i++){
    
        preXor[i+1] = preXor[i] ^ v[i];
    }

    // even check

    for(ll i = 0; i < n; i++){
    
        ll leftXor = preXor[i+1];
        ll rightXor = preXor[n] ^ preXor[i+1];

        if(leftXor == rightXor){

            cout << "YES" << nl;
            return;
        }
    }

    // odd check

    ll curr = 0;
    ll l = -1, r = -1;

    for(ll i = 0; i < n; i++){
    
        curr ^= v[i];

        if(l == -1 && curr == preXor[n]){

            l = i;
            curr = 0;
        }
        else if(r == -1 && curr == preXor[n]){

            r = i;
            ll remXor = preXor[n] ^ preXor[r+1];

            if(remXor == preXor[n]){

                cout << "YES" << nl;
                return;
            }
            else{

                cout << "NO" << nl;
                return;
            }
        }
    }

    cout << "NO" << nl;
    return;
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

        solve(v, n);
    }
}

