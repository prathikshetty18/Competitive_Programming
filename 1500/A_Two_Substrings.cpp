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

void solve(string &s, ll &n){

    // cout << s << nl;

    vll dp = {0, 0};

    for(ll i = 1; i < n; i++){

        // cout << "dp0: " << dp[0] << " dp1: " << dp[1] << nl;

        if(dp[0] == 0 && s[i-1] == 'A' && s[i] == 'B'){

            dp[0] = 1;
            i++;
        }
        else if(dp[0] == 1 && dp[1] == 0 && s[i-1] == 'B' && s[i] == 'A'){

            dp[1] = 1;
            i++;
        }

        if(dp[0] == 1 && dp[1] == 1){

            cout << "YES" << nl;
            return;
        }
    }

    dp = {0, 0};

    for(ll i = 1; i < n; i++){

        // cout << "dp0: " << dp[0] << " dp1: " << dp[1] << nl;

        if(dp[1] == 0 && s[i-1] == 'B' && s[i] == 'A'){

            dp[1] = 1;
            i++;
        }
        else if(dp[1] == 1 && dp[0] == 0 && s[i-1] == 'A' && s[i] == 'B'){

            dp[0] = 1;
            i++;
        }

        if(dp[0] == 1 && dp[1] == 1){

            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;

        string s;

        cin >> s;

        n = s.size();

        solve(s, n);
    }
}

