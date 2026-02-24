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

void solve(string &s1, string &s2, ll &n, ll &m){

    // Add one character to the string.
    // Remove one character from the string.
    // Replace one character in the string.

    vvll dp(n+2, vll(m+2, 1e4+1));

    for(ll i = n; i >= 0; i--){
    
        for(ll j = m; j >= 0; j--){
        
            if(i == n){

                dp[i][j] = m - j;
                continue;
            }
            if(j == m){

                dp[i][j] = n - i;
                continue;
            }


            if(s1[i] == s2[j]) dp[i][j] = min(dp[i][j], dp[i+1][j+1]);
            else{

                dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);     // remove one char from s1 and try to match;
                dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);     // add one char to s1 to match
                dp[i][j] = min(dp[i][j], 1 + dp[i+1][j+1]);   // replace s1 char and match
            }
        }
    }

    cout << dp[0][0] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;
        string s1, s2;

        cin >> s1 >> s2;

        n = s1.size();
        m = s2.size();

        solve(s1, s2, n, m);
    }
}

