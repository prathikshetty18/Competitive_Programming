#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n, ll &m){

    ll maxi = 1;
    ll ind = 1;

    for(int i = 0; i < n; i++){

        ll need = v[i]/m + (v[i] % m != 0);

        if(need >= maxi){

            maxi = max(maxi, need);
            ind = i+1;
        }
    }

    cout << ind << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t > 0){

        ll n, m;
        
        cin >> n >> m;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, m);

        t--;
    }
}

