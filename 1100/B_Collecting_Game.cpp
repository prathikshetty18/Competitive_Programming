#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<pair<ll, ll>> &v, ll &n){

    sort(v.begin(), v.end());

    vector<ll> preSum (n);

    preSum[0] = v[0].first;

    for(ll i = 1; i < n; i++){

        preSum[i] = preSum[i-1] + v[i].first;
    }

    vector<ll> ans (n);

    ans[v[n-1].second] = n-1;

    for(ll i = n-2; i >= 0; i--){

        ll minAns = i;

        if(preSum[i] >= v[i+1].first) minAns = ans[v[i+1].second];

        ans[v[i].second] = minAns;
    }

    for(int i = 0; i < n; i++){

        cout << ans[i] << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<pair<ll, ll>> v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i].first;
            v[i].second = i; 
        }

        solve(v, n);

        t--;
    }
}

