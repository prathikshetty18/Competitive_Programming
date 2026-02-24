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

vll calculateSubarrayCount(vll &a, ll &n){

    vll res (n+1, 0);

    for(ll i = 0; i < n; i++){
    
        if(a[i] == 0) continue;

        ll j = i;

        for(ll e = i+1; e < n; e++){
        
            if(a[e] == 1) j++;
            else break;
        }

        for(ll len = 1; len <= (j-i+1); len++){

            res[len] += j - i + 1 - len + 1;
        }

        i = j;
    }

    return res;
}

void solve(vll &a, vll &b, ll &n, ll &m, ll &k){

    vll subarrayCntA = calculateSubarrayCount(a, n);
    vll subarrayCntB = calculateSubarrayCount(b, m);

    // debug(subarrayCntA, subarrayCntB);

    ll cnt = 0;

    for(ll i = 1; i * i <= k; i++){

        if(((k % i) == 0) && (i <= n) && ((k/i) <= m)){

            // debug(i, k/i);

            cnt += subarrayCntA[i] * subarrayCntB[k/i];
        }

        if(((k % i) == 0) && (i <= m) && ((k/i) <= n) && ((k / i) != i)){

            // debug(i, k/i);

            cnt += subarrayCntA[k/i] * subarrayCntB[i];
        }
    }

    cout << cnt << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m, k;
        
        cin >> n >> m >> k;

        vll a (n), b (m);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < m; i++) cin >> b[i]; 

        solve(a, b, n, m, k);
    }
}

