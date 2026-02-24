#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << "-"; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n){
    

    ll flag = -1;
    ll ans = 1;

    for(ll i = 1; i < n; i++){

        if(v[i] == v[i-1]) continue;
        else if(v[i] >= v[i-1] && flag == 1) continue;
        else if(v[i] <= v[i-1] && flag == 0) continue;

        ans++;
        flag = v[i] >= v[i-1];
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

