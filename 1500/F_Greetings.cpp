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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(vpll &v, ll &n){

    sort(rall(v));

    ll tot = 0;

    oset<ll> st;

    for(ll i = 0; i < n; i++){
    
        ll ind = st.order_of_key(v[i].ss);
        st.insert(v[i].ss);
        tot += ind;
    }

    cout << tot << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vpll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i].ff >> v[i].ss; 


        solve(v, n);
    }
}

