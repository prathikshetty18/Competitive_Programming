#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool compatible(ll &x, ll &n){

    

    ll len1 = log2(x) + 1;
    ll len2 = log2(n) + 1;

    if(x == 0) len1 = 1;
    if(n == 0) len2 = 1;

    for(int i = 0; i < min(len1, len2); i++){

        if((((x >> i) & 1) == 0) && (((n >> i) & 1) == 1)){

            return false;
        }
    }

    return true;
    
}

void solve(vector<vector<ll>> &v, ll &n, ll &x){

    if(x == 0){

        cout << "Yes\n";
        return;
    }

    ll curr = 0;

    ll limit = 1 + log2(x);

    for(int i = 0; i < 3; i++){

        // cout << "In book Shelf: " << i+1 << nl;

        for(int j = 0; j < n; j++){


            if(v[i][j] == 0) continue;

            ll len = log2(v[i][j]) + 1;

            // cout << "j: " << j << " with len: " << len << " val: " << v[i][j] << nl;

            if(len <= limit && compatible(x, v[i][j])){

                curr = curr | v[i][j];
            }
            else{
                break;
            }

            if(curr == x){

                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, x;
        
        cin >> n >> x;

        vector<vector<ll>> v (3, vector<ll> (n));

        for(ll i = 0; i < n; i++) cin >> v[0][i]; 
        for(ll i = 0; i < n; i++) cin >> v[1][i]; 
        for(ll i = 0; i < n; i++) cin >> v[2][i]; 

        solve(v, n, x);

        t--;
    }
}

