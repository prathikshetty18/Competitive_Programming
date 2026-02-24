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

void solve(vll &v, ll &n){

    vvll dp(n, vll (3));

    // dp[i][j] = min rest days till day i performing activit j on day i
    // j = 0 -> Rest, j = 1 -> Code, j = 2 -> Gym


    if(v[0] == 0){

        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 1;
    }
    else if(v[0] == 1){

        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
    }
    else if(v[0] == 2){

        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][2] = 0;
    }
    else{

        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
    }

    vvll avail (4);
    avail[0] = {0};
    avail[1] = {0, 1};
    avail[2] = {0, 2};
    avail[3] = {0, 1, 2};


    for(ll i = 1; i < n; i++){

        dp[i][0] = 1 + dp[i-1][0];
        dp[i][1] = 1 + dp[i-1][0];
        dp[i][2] = 1 + dp[i-1][0];
    
        for(auto act : avail[v[i]]){

            ll mini = n+1;

            for(ll prev = 0; prev < 3; prev++){

                if(act != 0 && act == prev) continue;

                mini = min(mini, (act == 0) + dp[i-1][prev]);
            }

            dp[i][act] = mini;
        }
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << nl;

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

