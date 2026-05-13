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

bool isLex(string &s1, string &s2){

    ll len1 = 0, len2 = 0;

    while(len1 < s1.sz() && len2 < s2.sz() && s1[len1] == s2[len2]){

        len1++;
        len2++;
    }

    // skip equal chars

    if(len1 == s1.sz()){     // reached end of s1

        return true;
    }
    else if(len2 == s1.sz()){ // reached end of s2 but not s1

        return false;
    }

    // got unequal char before reaching end of any string

    if(s1[len1] <= s2[len2]){

        return true;
    }
    else return false;
}

void solve(vll &c, vector<string> &s, ll &n){

    vvll dp (n, vll (2, LLONG_MAX));
    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(ll i = 1; i < n; i++){
        
        string currRev = s[i];
        reverse(all(currRev));
        string prevRev = s[i-1];
        reverse(all(prevRev));
    
        ll currUnrevPrevUnrev = LLONG_MAX, currUnrevPrevRev = LLONG_MAX, currRevPrevUnrev = LLONG_MAX, currRevPrevRev = LLONG_MAX;

        if(isLex(s[i-1], s[i])) currUnrevPrevUnrev = dp[i-1][0];
        if(isLex(prevRev, s[i])) currUnrevPrevRev = dp[i-1][1];
        if(isLex(s[i-1], currRev)){

            if(dp[i-1][0] == LLONG_MAX) currRevPrevUnrev = LLONG_MAX;
            else currRevPrevUnrev = c[i] + dp[i-1][0];
        }
        if(isLex(prevRev, currRev)){

            if(dp[i-1][1] == LLONG_MAX) currRevPrevRev = LLONG_MAX;
            else currRevPrevRev = c[i] + dp[i-1][1];
        }

        // debug(currUnrevPrevUnrev, currUnrevPrevRev, currRevPrevUnrev, currRevPrevRev);

        dp[i][0] = min(currUnrevPrevUnrev, currUnrevPrevRev);
        dp[i][1] = min(currRevPrevUnrev, currRevPrevRev);
    }

    ll ans = min(dp[n-1][0], dp[n-1][1]);

    // debug(dp);

    cout << ((ans == LLONG_MAX) ? -1 : ans) << nl;
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

        vector<string> s (n);

        for(ll i = 0; i < n; i++){
        
            cin >> s[i];
        }

        solve(v, s, n);
    }
}

