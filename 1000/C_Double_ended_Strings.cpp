#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

ll f(ll ind1, ll ind2, string &a, string &b, vector<vector<ll>> &dp, ll &LCS){

    // cout << "ind1 : " << ind1 << " ind2: " << ind2 << nl;

    if(ind1 < 0 || ind2 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    f(ind1-1, ind2, a, b, dp, LCS);
    f(ind1, ind2-1, a, b, dp, LCS);

    if(a[ind1] == b[ind2]){

        dp[ind1][ind2] = 1 + f(ind1-1, ind2-1, a, b, dp, LCS);

        LCS = max(LCS, dp[ind1][ind2]);

        return dp[ind1][ind2];
    }

    // f(ind1-1, ind2, a, b, dp, LCS);
    // f(ind1, ind2-1, a, b, dp, LCS);

    return dp[ind1][ind2] = 0;
}

void solve(string &a, string &b){

    ll n, m;

    n = a.size();
    m = b.size();

    vector<vector<ll>> dp (n, vector<ll> (m, -1));

    ll LCS = 0;
    
    f(n-1, m-1, a, b, dp, LCS);

    cout << n + m - 2*LCS << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        string a, b;

        cin >> a >> b;

        solve(a, b);
    }
}

