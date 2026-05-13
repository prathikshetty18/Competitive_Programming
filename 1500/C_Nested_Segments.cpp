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

bool comp(vll &v1, vll &v2){

    if(v1[0] != v2[0]){

        return v1[0] < v2[0];
    }
    else return v1[1] > v2[1];
}

void solve(vvll &v, ll &n){

    // debug(v);

    sort(all(v), comp);

    // debug(v);

    for(ll i = 1; i < n; i++){

        if(v[i][1] <= v[i-1][1]){

            cout << v[i][2] + 1 << sp << v[i-1][2] + 1<< nl;
            return;
        }
    }

    cout << -1 << sp << -1 << nl;
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vvll v (n, vll (3));

        for(ll i = 0; i < n; i++){
            
            
            cin >> v[i][0] >> v[i][1];
            v[i][2] = i; 
        }

        solve(v, n);
    }
}

