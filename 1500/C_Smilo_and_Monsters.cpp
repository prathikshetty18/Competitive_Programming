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

void solve(vll &v, ll &n){

    sort(all(v));

    // print(v);

    ll l = 0, r = n-1, steps = 0;

    ll x = 0;

    while(l < r){

        // cout << "l: " << l << " r: " << r << " x: " << x << nl;
        // print(v);

        if(x >= v[r]){

            v[r] = 0;
            steps++;
            r--;
            x = 0;
            continue;
        }

        if(v[l] + x > v[r]){

            ll diff = v[r] - x;

            steps += diff;
            v[l] -= diff;
            x += diff;
        }
        else if(v[l] + x <= v[r]){

            steps += v[l];
            x += v[l];
            v[l] = 0;
            l++;
        }
    }

    // cout << "l: " << l << " r: " << r << " x: " << x << nl;
    // print(v);


    if(l == r && v[l] != 0){

        steps += (v[l] - x + 1)/2;
        v[l] -= (v[l] - x + 1)/2;
        if(v[l] != 0) steps++;
        v[l] = 0;
    }

    cout << steps << nl;
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

