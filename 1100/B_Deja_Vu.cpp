#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, vector<ll> &x, ll &n, ll &q){

    ll mini = 31;

    for(int i = 0; i < q; i++){

        if(x[i] < mini){

            mini = min(mini, x[i]);

            for(ll j = 0; j < n; j++){

                ll div = 1 << x[i];
                ll add = 1 << (x[i]-1);

                if(v[j] % div == 0) v[j] += add;
            }
        }
    }

    for(auto ele : v){

        cout << ele << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, q;
        
        cin >> n >> q;

        vector<ll> v (n), x (q);

        for(ll i = 0; i < n; i++) cin >> v[i]; 
        for(ll i = 0; i < q; i++) cin >> x[i]; 

        solve(v, x, n, q);

        t--;
    }
}

