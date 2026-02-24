#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<vector<ll>> &mat, ll n){

    // for(ll i = 0; i < n; i++){

    //     for(ll j = 0; j < mat[i].size(); j++) cout << mat[i][j] << " "; 

    //     cout << endl;
    // }

    // cout << endl;

    if(n == 1){

        cout << mat[0][0] << endl;
        return;
    }

    ll mini = INT_MAX;
    ll secMini = INT_MAX;
    ll ans = 0;

    for(ll i = 0; i < n; i++){

        mini = min(mini, mat[i][0]);
        secMini = min(secMini, mat[i][1]);
        ans += mat[i][1];
    }

    // cout << "mini: " << mini << " secMini: " << secMini << " ans: " << ans << endl;

    ans = ans + mini - secMini;

    cout << ans << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<vector<ll>> mat (n);

        for(ll i = 0; i < n; i++){

            ll m;

            cin >> m;

            mat[i].resize(m);

            for(ll j = 0; j < m; j++) cin >> mat[i][j]; 

            sort(mat[i].begin(), mat[i].end());
        }

        solve(mat, n);

        t--;
    }
}

