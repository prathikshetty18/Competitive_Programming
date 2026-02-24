#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool possible(vector<ll> &v, ll &n, ll &c, ll &w){

    ll sumSq = 0;

    for(ll i = 0; i < n; i++){

        sumSq += (v[i] + 2*w) * (v[i] + 2*w);
        
        if(sumSq >= c) return true; 
    }

    return false;
}

void solve(vector<ll> &v, ll &n, ll &c){

    ll l = 1;
    ll r = 1e9;

    ll mid;

    while(l <= r){

        // cout << "l: " << l << " r: " << r << nl;

        mid = l + (r-l)/2;

        if(possible(v, n, c, mid)){

            r = mid-1;
        }
        else{

            l = mid+1;
        }

    }

    cout << l << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, c;
        
        cin >> n >> c;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, c);

        t--;
    }
}

