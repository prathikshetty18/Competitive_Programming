#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &have, vector<ll> &want, ll &n){

    vector<ll> diff;

    for(ll i = 0; i < n; i++){

        diff.push_back(have[i] - want[i]);
    }

    sort(rall(diff));

    ll count = 0;
    ll j = n-1;

    for(int i = 0; i < n; i++){

        while(j > i && diff[i] + diff[j] < 0) j--;

        if(j <= i) break;

        count++; j--;
    }

    cout << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> have (n);
        vector<ll> want (n);

        for(ll i = 0; i < n; i++) cin >> want[i]; 
        for(ll i = 0; i < n; i++) cin >> have[i];

        solve(have, want, n);
    }
}

