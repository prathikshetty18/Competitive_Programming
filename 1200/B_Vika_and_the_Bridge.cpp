#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &k){

    vector<ll> last (k+1, 0);

    unordered_map<ll, pair<ll, ll>> mp;     // maxi1, maxi2

    for(ll i = 0; i < n; i++){

        ll col = v[i];

        ll dis = i + 1 - last[col] - 1;

        if(dis >= mp[col].first){

            mp[col].second = mp[col].first;
            mp[col].first = dis;
        }
        else if(dis > mp[col].second){

            mp[col].second = dis;
        }

        last[col] = i + 1;

        // cout << "col: " << col << " max1: " << mp[col].first << " maxi2: " << mp[col].second << " dis: " << dis << nl;

    }

    for(ll col = 1; col <= k; col++){

        ll dis = n + 1 - last[col] - 1;

        if(dis >= mp[col].first){

            mp[col].second = mp[col].first;
            mp[col].first = dis;
        }
        else if(dis > mp[col].second){

            mp[col].second = dis;
        }

        // cout << "col: " << col << " max1: " << mp[col].first << " maxi2: " << mp[col].second << nl;

    }

    ll ans = n;

    for(ll col = 1; col <= k; col++){

        // cout << "col: " << col << " max1: " << mp[col].first << " maxi2: " << mp[col].second << nl;

        ans = min(ans, max(mp[col].first/2, mp[col].second));
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);
    }
}

