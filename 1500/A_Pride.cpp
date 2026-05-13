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

void solve(vll &v, ll &n){

    ll minGcdLen = LLONG_MAX;
    ll oneCount = 0;

    vvll gcdMap (n, vll (n, 0));

    for(ll i = 0; i < n; i++){

        gcdMap[i][i] = v[i];
        oneCount += (v[i] == 1);
    
        for(ll j = i+1; j < n; j++){
        
            gcdMap[i][j] = gcd(gcdMap[i][j-1], v[j]);

            if(gcdMap[i][j] == 1){

                minGcdLen = min(minGcdLen, j - i + 1);
            }
        }
    }

    if(oneCount == 0 && minGcdLen == LLONG_MAX){

        cout << -1 << nl;
        return;
    }
    if(oneCount != 0){

        cout << n - oneCount << nl;
        return;
    }
    else{

        cout << n - 1 + (minGcdLen - 1) << nl;
    }

    // debug(gcdMap, oneCount, minGcdLen);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

