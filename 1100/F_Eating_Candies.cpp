#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n){

    vector<ll> pre (n);
    vector<ll> suf (n);

    pre[0] = v[0];
    suf[n-1] = v[n-1];

    for(ll i = 1; i < n; i++){

        pre[i] = v[i] + pre[i-1];
    }

    for(ll i = n-2; i >= 0; i--){

        suf[i] = v[i] + suf[i+1];
    }

    ll l = 0;
    ll r = n-1;
    ll maxi = 0;

    while(l < r){

        if(pre[l] == suf[r]){

            maxi = max(maxi, l + 1 + (n - r));
            l++;
            r--;
        }
        else if(pre[l] > suf[r]){

            r--;
        }
        else{

            l++;
        }
    }

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

