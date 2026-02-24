#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

bool comp(pair<ll, ll> &a, pair<ll, ll> &b){

    return a.first > b.first;
}

void solve(vector<pair<ll, ll>> &v, ll &n){

    sort(v.begin(), v.end(), comp);

    deque<ll> dq;
    dq.push_front((ll)0);

    ll start = 2;  
    ll ans = 0;

    for(auto it : v){

        ans += 2 * (start/2) * it.first;

        if(start % 2 == 0) dq.push_front(it.second);
        if(start % 2 == 1) dq.push_back(it.second);

        start++;
    }

    start = 1;

    cout << ans << nl;

    unordered_map<ll, ll> mp;

    for(auto ele : dq){

        mp[ele] = start;
        start++;
    }

    for(ll i = 0; i <= n; i++){

        cout << mp[i] << sp;
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
            v[i].second = i+1;
        }

        solve(v, n);

        t--;
    }
}

