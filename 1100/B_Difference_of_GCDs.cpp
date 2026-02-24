#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(ll &n, ll &l, ll &r){

    vector<ll> ans;

    for(ll i = 1; i <= n; i++){

        ll min = (((l-1)/i)+1)*i;

        if(min > r){

            cout << "NO\n";
            return;
        }

        ans.push_back(min);
    }

    cout << "YES\n";

    for(auto ele : ans){

        cout << ele << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n, l, r;
        
        cin >> n >> l >> r;

        solve(n, l, r);
    }
}

