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

    sort(all(v));

    map<ll, ll> mp; // key : last val

    for(ll i = 0; i < n; i++){
    
        mp[v[i]]++;

        if(mp[v[i]-1] != 0) mp[v[i]-1]--;
    }

    ll ans = 0;


    for(auto it : mp){

        ans += it.second;
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

