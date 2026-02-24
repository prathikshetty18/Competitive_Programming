#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

ll helper(vector<pair<ll,ll>> &fir, vector<pair<ll,ll>> &sec, vector<pair<ll,ll>> &thi, ll &n){

    ll ind1 = -1, ind2 = -1;

    ll sum = fir.back().first;
    ind1 = fir.back().second;

    for(ll i = n-1; i >= 0; i--){

        if(sec[i].second == ind1) continue;

        sum += sec[i].first;
        ind2 = sec[i].second;
        break;
    }

    for(ll i = n-1; i >= 0; i--){

        if(thi[i].second == ind1 || thi[i].second == ind2) continue;

        sum += thi[i].first;
        ind2 = thi[i].second;
        break;
    }

    return sum;
}

void solve(vector<pair<ll,ll>> &a, vector<pair<ll,ll>> &b, vector<pair<ll,ll>> &c, ll &n){
 
    ll ans = 0;

    ans = max(ans, helper(a, b, c, n));
    ans = max(ans, helper(a, c, b, n));
    ans = max(ans, helper(b, a, c, n));
    ans = max(ans, helper(b, c, a, n));
    ans = max(ans, helper(c, a, b, n));
    ans = max(ans, helper(c, b, a, n));

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

        vector<pair<ll,ll>> a (n);
        vector<pair<ll,ll>> b (n);
        vector<pair<ll,ll>> c (n);

        for(ll i = 0; i < n; i++){
            
            cin >> a[i].first; 

            a[i].second = i;
        }

        for(ll i = 0; i < n; i++){
            
            cin >> b[i].first; 

            b[i].second = i;
        }        
        
        for(ll i = 0; i < n; i++){
            
            cin >> c[i].first; 

            c[i].second = i;
        }

        sort(all(a));
        sort(all(b));
        sort(all(c));

        solve(a, b, c, n);
    }
}

