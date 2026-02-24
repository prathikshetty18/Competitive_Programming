#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n){

    unordered_map<ll, ll> mp;

    ll maxi = 1;

    for(auto it : v){

        mp[it]++;
        maxi = max(maxi, mp[it]);
    }

    if(maxi > 1){

        cout << "YES" << nl;
        return;
    }
    else{

        cout << "NO" << nl;
    }


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

