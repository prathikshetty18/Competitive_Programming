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

void solve1(string &s, ll &n){  // 0 based indexing

    ll ans = 1;

    ll currSize = 0;

    for(ll i = 0; i < n; i++){
    
        if(s[i] == 'a'){

            currSize = mod_add(currSize, 1);
        }
        else if(s[i] == 'b'){

            ans = mod_mul(ans, mod_add(currSize, 1));
            currSize = 0;
        }
    }

    ans = mod_mul(ans, mod_add(currSize, 1));

    cout << ans - 1 << nl;
}

void solve2(string &s, ll &n){  // 1 based indexing

    vector<ll> prevABeforeB(n, -1);

    ll lastA = -1;
    ll bestA = -1;

    for(ll i = 0; i < n; i++){

        if(s[i] == 'a'){
            prevABeforeB[i] = bestA;
            lastA = i;
        }

        if(s[i] == 'b'){
            bestA = lastA;
        }
    }

    vll dp (n+1, 0);
    
    dp[0] = (s[0] == 'a');

    for(ll i = 1; i < n; i++){
    
        if(s[i] != 'a'){

            dp[i] = dp[i-1];
        }
        else{

            dp[i] = mod_add(dp[i-1], 1);
            if(prevABeforeB[i] != -1) dp[i] = mod_add(dp[i], dp[prevABeforeB[i]]);
        }
    }

    cout << dp[n-1] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        string s;
        ll n;
        
        cin >> s;

        n = s.sz();

        solve2(s, n);
    }
}

