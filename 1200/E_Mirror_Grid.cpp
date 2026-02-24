#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<string> &mat, ll &n){

    ll count = 0;

    for(ll i = 0; i < n/2; i++){

        for(ll j = i; j < n - i - 1; j++){

            // cout << "i: " << i << " j: " << j << nl;
            // cout << "j: " << j << " n-1-i: " << n-1-i << nl;
            // cout << "n-1-i: " << n-1-i << " n-1-j: " << n-1-j << nl;
            // cout << "n-1-j: " << n-1-j << " i: " << i << nl << nl;

            ll ones = 0;
            ll zeros = 0;

            ones += mat[i][j] == '1';
            zeros += mat[i][j] == '0';

            ones += mat[j][n-1-i] == '1';
            zeros += mat[j][n-1-i]== '0';

            ones += mat[n-1-i][n-1-j] == '1';
            zeros += mat[n-1-i][n-1-j]== '0';

            ones += mat[n-1-j][i] == '1';
            zeros += mat[n-1-j][i] == '0';

            if(ones >= 2) count += zeros;
            else count += ones;
        }
    }
    
    cout << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<string> mat (n);

        for(ll i = 0; i < n; i++){
            
            cin >> mat[i]; 
        }

        solve(mat, n);
    }
}

