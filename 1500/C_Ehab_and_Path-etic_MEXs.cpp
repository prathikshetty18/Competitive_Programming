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

void solve(vpll &edges, ll &n){

    vll deg (n+1, 0);
    ll maxDegVal = 3;
    ll maxDegNode = 0;
 
    for(auto p : edges){

        deg[p.ff]++;
        if(deg[p.ff] >= maxDegVal){
            maxDegVal = deg[p.ff];
            maxDegNode = p.ff;
        }
        deg[p.ss]++;
        if(deg[p.ss] >= maxDegVal){
            maxDegVal = deg[p.ss];
            maxDegNode = p.ss;
        }
    }

    ll val = (maxDegNode != 0) ? maxDegVal : 0;

    // debug(deg, maxDegVal, maxDegNode);
     
    for(auto p : edges){

        if(p.ff == maxDegNode || p.ss == maxDegNode){

            cout << --maxDegVal << nl;
        }
        else cout << val++ << nl;
    }

    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vpll v (n-1);

        for(ll i = 0; i < n - 1; i++) cin >> v[i].ff >> v[i].ss; 

        solve(v, n);
    }
}

