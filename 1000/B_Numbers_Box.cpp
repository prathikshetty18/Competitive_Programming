#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, m;
        
        cin >> n >> m;

        vector<vector<ll>> mat (n, vector<ll> (m));

        ll mini = LLONG_MAX;
        ll sum = 0;
        ll negCount = 0;

        for(ll i = 0; i < n; i++){

            for(ll j = 0; j < m; j++){

                cin >> mat[i][j];

                mini = min(mini, abs(mat[i][j]));
                sum += abs(mat[i][j]);

                if(mat[i][j] < 0) negCount++;
            }
        }

        if(negCount % 2 == 1) sum -= 2 * mini;

        cout << sum << nl;

        t--;
    }
}

