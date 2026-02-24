#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<vector<ll>> &mat, ll &n, ll &m){

    ll ans = 0;

    for(ll i = 0; i < m; i++){

        vector<ll> pre (n+1, 0);

        for(ll j = 1; j < n; j++){

            pre[j] = pre[j-1] + mat[i][j-1];

            ans += mat[i][j] * j - pre[j];
        }

    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vector<vector<ll>> mat (m, vector<ll> (n));

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < m; j++){
            
                cin >> mat[j][i];

            }
        }


        for(ll i = 0; i < m; i++){

            sort(all(mat[i]));
        }

        solve(mat, n, m);
    }
}

