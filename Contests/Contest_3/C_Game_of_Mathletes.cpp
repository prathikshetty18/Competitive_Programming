#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll n, ll k){

    sort(v.begin(), v.end());

    int l = 0;
    int r = n-1;

    int ans = 0;

    while(l < r){

        if(v[l] + v[r] == k){
            ans++;
            l++;
            r--;
        }
        else if(v[l] + v[r] > k) r--;
        else l++;
    }

    cout << ans << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n);

        for(int i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);

        t--;
    }
}

