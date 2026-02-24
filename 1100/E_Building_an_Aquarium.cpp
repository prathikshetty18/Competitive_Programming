#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool possible(vector<ll> &v, ll &n, ll &x, ll &h){

    ll total = 0;

    for(ll i = 0; i < n; i++){

        total += max(h - v[i], (ll)0);
    }

    if(total <= x) return true;
    else return false;
}

void solve(vector<ll> &v, ll &n, ll &x){

    ll l = 1;
    ll r = x + 1e9;

    ll mid;

    while(l <= r){

        // cout << "l: " << l << " r: " << r << nl;

        mid = l + (r-l)/2;

        if(possible(v, n, x, mid)){

            l = mid+1;
        }
        else{

            r = mid-1;
        }
    }

    cout << r << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, x;
        
        cin >> n >> x;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, x);

        t--;
    }
}

