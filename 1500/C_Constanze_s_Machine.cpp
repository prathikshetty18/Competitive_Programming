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

    vll dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    if(s[0] == 'w' || s[0] == 'm'){

        cout << 0 << nl;
        return;
    }

    for(ll i = 1; i < n; i++){
        
        if(s[i] == 'w' || s[i] == 'm'){

            cout << 0 << nl;
            return;
        }
        else if(s[i] == 'u' && s[i-1] == 'u'){

            dp[i+1] = mod_add(dp[i+1], mod_add(dp[i], dp[i-1]));
        }
        else if(s[i] == 'n' && s[i-1] == 'n'){

            dp[i+1] = mod_add(dp[i+1], mod_add(dp[i], dp[i-1]));
        }
        else dp[i+1] = mod_add(dp[i+1], dp[i]);
    }

    cout << dp[n] << nl;
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

