#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll n, ll a, ll b){

    ll ans = b - 1;

    for(int i = 0; i < n; i++){

        ans += min(a-1, v[i]);
    }

    ans++;

    cout << ans << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll a, b, n;
        
        cin >> a >> b >> n;

        vector<ll> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, a, b);

        t--;
    }
}

