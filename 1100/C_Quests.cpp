#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &a, vector<ll> &b, ll &n, ll &k){

    ll prevMax = LLONG_MIN;
    ll ans = LLONG_MIN;

    ll curr = 0;
    ll quests = 0;

    for(int i = 0; i < n && quests < k; i++){

        curr += a[i];
        quests++;
        prevMax = max(prevMax, b[i]);

        ans = max(ans, curr + (k-quests)*prevMax);
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> a (n),  b (n);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n, k);

        t--;
    }
}

