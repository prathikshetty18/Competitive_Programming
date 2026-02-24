#include <bits/stdc++.h>
using namespace std;

#define ll long long

// ll nCr(ll &n, ll &r){

//     r = min(r, n-r);

//     ll ans = 1;

//     for(ll i  = 1; i <= r; i++){

//         ans *= (n - i + 1);
//         ans /= i;
//     }

//     return ans;
// }

ll totalCount(ll &count, ll &n, ll &k){

    ll ans = 0;

    for(ll i = k; i <= min(n, count); i++){

        ans += count - i + 1;
    }

    return ans;
}

void solve(vector<ll> &v, ll &n, ll &k, ll &temp){

    ll count = 0;
    ll ans = 0;

    for(int i = 0; i < n; i++){

        if(v[i] <= temp){

            count++;
        }
        else{

            ans += totalCount(count, n, k);
            count = 0;
        }
    }

    ans += totalCount(count, n, k);

    cout << ans << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k, temp;
        
        cin >> n >> k >> temp;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i];         

        solve(v, n, k, temp);

        t--;
    }
}

