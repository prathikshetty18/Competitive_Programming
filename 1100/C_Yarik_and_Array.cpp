#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n){

    vector<vector<ll>> dp (n+1 , vector<ll> (2, -1e9));

    ll maxi = LLONG_MIN;

    dp[0][abs(v[0]%2)] = v[0];

    maxi = max(maxi, v[0]);

    for(ll i = 1; i < n; i++){

        int mod = abs(v[i]%2);

        dp[i][mod] = max(v[i], v[i] + (dp[i-1][!mod] == -1e9 ? 0 : dp[i-1][!mod]));
        dp[i][!mod] = -1e9;

        maxi = max(maxi, dp[i][mod]);
    }

    // cout << "v: " << sp;

    // for(auto ele : v){

    //     cout << ele << sp;
    // }

    // cout << nl << "dp[i][0]: " << sp;;

    // for(int i = 0; i < n; i++){

    //     cout << dp[i][0] << sp;
    // }

    // cout << nl << "dp[i][1]: " << sp;

    // for(int i = 0; i < n; i++){

    //     cout << dp[i][1] << sp;
    // }

    // cout << nl << nl;

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

