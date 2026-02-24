#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<pair<ll,ll>> &v, ll &n, ll &k, ll &a, ll &b){

    ll mini = abs(v[a-1].first -v[b-1].first) + abs(v[a-1].second -v[b-1].second);

    ll cost1 = LLONG_MAX, cost2 = LLONG_MAX;

    for(ll i = 0; i < k; i++){

        cost1 = min(cost1, abs(v[i].first - v[a-1].first) + abs(v[i].second - v[a-1].second));
        cost2 = min(cost2, abs(v[i].first - v[b-1].first) + abs(v[i].second - v[b-1].second));
    }

    if(k > 0){

        mini = min(mini, cost1 + cost2);
    }


    cout << mini << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k, a, b;
        
        cin >> n >> k >> a >> b;

        vector<pair<ll,ll>> v (n);

        for(ll i = 0; i < n; i++){

            cin >> v[i].first; 
            cin >> v[i].second;
        }

        solve(v, n, k, a, b);

        t--;
    }
}

