#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll &n, ll &k){

    ll maxi = LLONG_MIN;
    ll evencount = 0;

    for(auto ele : v){

        evencount += ele % 2 == 0;

        maxi = max(maxi, ele % k == 0 ? k : ele % k);
    }

    if(k == 4){

        if(evencount == 0 && n >= 2 && maxi <= 2){

            cout << 2 << endl;
            return;
        }
        else if(evencount == 1 && n >= 2 && maxi != 4){

            cout << 1 << endl;
            return;
        }
        else if(evencount >=2){

            cout << 0 << endl;
            return;
        }
    }

    cout << k - maxi << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);

        t--;
    }
}

