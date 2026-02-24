#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<vector<ll> > &v, ll &n, ll &k){

    ll steps = 0;

    for(ll i = 0; i < n; i++){

        for(ll j = 0; j < n; j++){

            ll adjRow = n-i-1;
            ll adjCol = n-j-1;

            // cout << "i: " << i << " j: " << j << nl;
            // cout << "adjRow: " << adjRow << " adjCol: " << adjCol << nl;

            if(v[i][j] != v[adjRow][adjCol]){
                
                v[i][j] = v[adjRow][adjCol];
                steps++;
            }

            if(steps > k){

                cout << "NO\n";
                return;
            }
        }
    }

    // cout << "steps: " << steps << nl;

    if(((k-steps)%2 == 1) && (n % 2 != 1)){

        cout << "NO\n";
        return;
    }

    if(steps <= k){

        cout << "YES\n";
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int start = t;

    int startn = -1;

    while(t > 0){

        ll n, k;

        
        cin >> n >> k;
        if(startn == -1) startn = n;

        vector<vector<ll>> v (n, vector<ll> (n));

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < n; j++){
                
                cin >> v[i][j]; 
            }
        }

        solve(v, n, k);


        t--;

        // if((start == 100) && (t == start-21) && (startn == 1)){


        //     for(ll i = 0; i < n; i++){

        //         cout << "n: " <<  n << " k: " << k << nl;

        //         for(ll j = 0; j < n; j++){
                    
        //             cout << v[i][j] << sp; 
        //         }

        //         cout << nl;
        //     }
        // }
    }
}

